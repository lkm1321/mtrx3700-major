/************************************************************ 
The contents of this file are subject to the Pumpkin Salvo
License (the "License").  You may not use this file except
in compliance with the License. You may obtain a copy of
the License at http://www.pumpkininc.com, or from
warranty@pumpkininc.com.

Software distributed under the License is distributed on an
"AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express
or implied. See the License for specific language governing
the warranty and the rights and limitations under the
License.

The Original Code is Salvo - The RTOS that runs in tiny
places(TM). Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). All Rights Reserved.

$Source: C:\\RCS\\d\\salvo\\src\\sched.c,v $
$Author: aek $
$Revision: 3.33 $
$Date: 2003-10-20 18:05:18-07 $

Functions to run tasks.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS


/************************************************************ 
****                                                     ****
**                                                         **
OSSched()

The scheduler has three parts -- first, a part to deal with 
events that have been signaled, then a part for tasks with 
expired delays and timeouts, and then the part that actually 
dispatches the task.

The first part is only active when events are used. A FIFO
queue of signaled events is processed and for each event,
the waiting task is made eligible. Tasks that were waiting
with timeouts are removed from the delay queue and have the
associated fields cleared.

The second part is active only when delays and/or timeouts are
enabled. If one or more delays have expired, those tasks
must be made eligible again. By controlling interrupts here
we can prevent interrupts from being disabled for an unduly
long time.

The third part executes the highest-priority task in the 
eligible queue, and upon its return to the scheduler (i.e. 
when it context-switches back to the scheduler, from whence 
it came) we deal with the task according to its (new) status. 

Normally, tasks will return to the scheduler in OSTCB_TASK_ELIGIBLE,
in which case they get re-enqueued into the eligible queue.  
But there are some commonly-occuring cases (e.g. when a task 
is delayed or delays itself) where the task isn't re-enqueued 
automatically into the eligible queue.

NOTE: tasks in the delay queue should be only OSTCB_TASK_WAITING_TO
or OSTCB_TASK_DELAYED.
  
NOTE: Needs interrupt-control work if OSMONITOR_KEYWORD_PRE
is used ...
  
**                                                         **
****                                                     ****
************************************************************/
#if !OSUSE_INLINE_OSSCHED

#define __OSSCHED_SCHED_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
void OSSched( void )
OSMONITOR_KEYWORD_POST
#endif
{    
    /* NOTE: this is incompatible with in-lining OSSched()! */
    #if OSENABLE_DELAYS && OSUSE_ARRAYS
    OStypeTcbP nextTcbP;
    #endif


    /* this hook is here so that analysis can be done on	*/
    /*  the scheduler. It's not intended for general use.  	*/
    #if OSENABLE_OSSCHED_ENTRY_HOOK
    OSSchedEntryHook();
    #endif
        
    /* hit the watchdog timer now, since startup may have   */
    /*  taken a while ...                                   */    
    OSCLEAR_WATCHDOG_TIMER(); 

    OSBeginCriticalSection();
    
    #if !OSUSE_INLINE_OSSCHED
    OSIncCallDepth();
    #endif
	
    /********************************************************/
    /* first we have to process signaled events. Each time  */
    /*  an event is signaled, one or all of the tasks       */
    /*  waiting the event are added to the signaled event   */
    /*  queue, a simple FIFO queue (for speed and behavior).*/
    /* As of v2.3, tasks started via OSStartTask() may also */
    /*  be in this queue.                                   */
    /* this loop continues until there are no more tasks    */
    /*  in the queue. Tasks can be added to the queue via   */
    /*  interrupts that occur during queue processing.      */
    #if OSENABLE_SIGQ
    while ( OSsigQoutP ) {
    
        /* handle to highest-priority task waiting the      */
        /*  event at the head of the event queue.           */
        OScTcbP = OSsigQoutP;
            
        /* advance event queue out pointer, and null the    */
        /*  tcb's nextTcbP since we just removed it from    */
        /*  the queue.                                      */
        OSsigQoutP = OScTcbP->nextTcbP;
        OScTcbP->nextTcbP = NULL;
        
        /* task is no longer tied to an event, so we'll     */
        /*  wipe that field for others to use.              */
        /* if task was made to wait with a timeout, then it */
        /*  needs to be removed from the delay queue. Note  */
        /*  that we could also reset tcbP->nextDlyTcbP,     */
        /*  tcbP->dly.delay here, but it's not absolutely   */
        /*  necessary.                                      */
        #if OSENABLE_TIMEOUTS    
        if ( OScTcbP->status.bits.state == OSTCB_TASK_WAITING_TO ) {
            OScTcbP->u.ecbP = NULL;
            OSDelDelay(OScTcbP);
        }
        #endif
        
        /* make task OSTCB_TASK_ELIGIBLE and enqueue it into the  */
        /*  eligible queue now that it has a clean,         */
        /*  unenqueued tcb. If we're doing fast signaling,  */
        /*  make the task OSTCB_TASK_SIGNALED so that OS_WaitXyz()*/
        /*  can differentiate among the various ways of     */
        /*  getting there. Also, since tasks can be in here */
        /*  via OSStartTask(), etc., we need to             */
        /*  differentiate between those that were signaled  */
        /*  (will be either OSTCB_TASK_WAITING or OSTCB_TASK_WAITING_TO)*/
        /*  and those that were "blindly" made eligible.    */
        #if !OSENABLE_FAST_SIGNALING
        OSInsElig(OScTcbP);
        #else
        if ( OScTcbP->status.bits.state != OSTCB_TASK_ELIGIBLE )
            OScTcbP->status.bits.state = OSTCB_TASK_SIGNALED;
        OSInsPrio(OScTcbP, &OSeligQP);
        #endif

        
        /* prior to re-enabling interrupts we must update   */
        /*  the inP. If we've reached the end of the queue, */
        /*  inP must be reset, o/wise leave it alone.       */    
        if ( !OSsigQoutP )
            OSsigQinP = NULL;
            
        /* let interrupts in, as we've successfully         */
        /*  processed one task, and other events may be     */
        /*  signaled. InP and OutP are up-to-date.          */
        OSSuspendCriticalSection();
        OSResumeCriticalSection();
    }
    #endif /* #if OSENABLE_SIGQ */

    
    
    /********************************************************/
    /* next we have to process delayed tasks. Either a      */
    /*  counter (when collecting lost ticks) or a flag (a   */
    /*  semaphore, actually) is only sampled here.          */
    /* we'll use OScTcbP as a handle, as it has no real     */
    /*  meaning outside of the dispatcher part of OSSched() */
    /*  anyway ...                                          */
    /* Note that since interrupts are disabled here, no     */
    /*  additional protection against interference from     */
    /*  OSTimer() is required.                              */
    #if OSENABLE_DELAYS
    
    while ( OSlostTicks ) {
        /* now we're comitted to as many ticks' worth of    */
        /*  delay processing as have occurred since the     */
        /*  last call to OSSched(). Normally, this will be  */
        /*  either 0 or 1. But in those cases where a task  */
        /*  took more than 2 ticks to yield to the          */
        /*  scheduler, this number will exceed 1. By        */
        /*  processing all the ticks, we "catch up" to      */
        /*  the current system tick in terms of task        */
        /*  delays, etc.                                    */
        OSlostTicks--;
            
        /* we'll use a local handle to speed things up.     */
        OScTcbP = OSdelayQP;
    
        /* for a non-empty delay queue, we                  */
        /*  must decrement the first element's delay. No    */
        /*  further decrements are necessary due to the     */
        /*  differential nature of the delay queue. No more */
        /*  changes to any tasks' delays will be made after */
        /*  this point.                                     */
        #if !OSUSE_ARRAYS
        if ( OScTcbP )
            --(OScTcbP->dly.delay);
        #endif
    
    
        /* we'll process every task in the delay queue until*/
        /*  we either reach the end of the queue or find a  */
        /*  task with a non-zero delay.                     */
        #if !OSUSE_ARRAYS
        while ( OScTcbP && !OScTcbP->dly.delay )
        {
        #else
        while ( OScTcbP )
        {
        #endif
        
            /* tcbP points to a task with an expired delay. */
            /* remove task from the delay queue and reset   */
            /*   its delay queue pointers.                  */
    
            #if !OSUSE_ARRAYS && !OSENABLE_TIMEOUTS
            OSdelayQP = OScTcbP->nextTcbP;
            
            #if OSCLEAR_UNUSED_POINTERS
            OScTcbP->nextTcbP = NULL;
            #endif
            #endif
            
            
            #if !OSUSE_ARRAYS && OSENABLE_TIMEOUTS
            OSdelayQP = OScTcbP->nextDlyTcbP;
            
            #if OSCLEAR_UNUSED_POINTERS
            OScTcbP->nextDlyTcbP = NULL;
            #endif 
            #endif 
    
    
            #if OSUSE_ARRAYS
            nextTcbP = OScTcbP->nextDlyTcbP;
            if (!(--(OScTcbP->dly.delay))) {
                OSDelDelay(OScTcbP);
            #endif     
            
            
            /* at this point we've removed the task from    */
            /*  delay queue and cleaned up any issues       */
            /*  relating to the task having been delayed.   */
            /*  Now we have to re-enqueue it into the       */
            /*  eligible queue. If timeouts are enabled, we */
            /*  must check to see if the task was not in    */
            /*  fact delayed but was waiting with a timeout */
            /*  for an event to happen -- in that case, the */
            /*  task returns to the eligible queue, but     */
            /*  with an indication that a timeout occurred. */
            
            /* additionally, we need to time-stamp the task */
            /*  for OS_Interval()'s use.                    */
            #if OSENABLE_TICKS
            OScTcbP->dly.timestamp = (OStypeTS) OStimerTicks;
            #endif
            
            /* task wasn't waiting for anything when it     */
            /*  timed out, so make it OSTCB_TASK_ELIGIBLE and */
            /*  enqueue it into the eligible queue. This    */
            /*  is the normal course of action ...          */
            #if !OSENABLE_TIMEOUTS
            OSInsElig(OScTcbP);
            
            /* a task that timed out while waiting failed   */
            /*  to obtain an event. Remove it from the      */
            /*  event's waiting list and invoke special     */
            /*  handling.                                   */
            /* Note that this action of deleting a task     */
            /*  from the priority queue is the only place   */
            /*  where ecbP is used, and it's used here to   */
            /*  speed things up considerably.               */
            #else /* #if OSENABLE_TIMEOUTS */    
            if ( OScTcbP->status.bits.state == OSTCB_TASK_WAITING_TO )
            {
                
                OSMsg("OSSched",
                  OSMakeStr("task %d timed out waiting for event %d.",
                    OStID(OScTcbP), 
                    OSeID(OScTcbP->u.ecbP)));
                
                OSDelPrio(OScTcbP, &(OScTcbP->u.ecbP->tcbP));
                OScTcbP->u.ecbP = NULL;
                
                /* put it back into the eligible queue as   */
                /*  OSTCB_TASK_WAITING_TO.                  */        
                OSInsPrio(OScTcbP, &OSeligQP);
                
                /* log the timeout event if we're keeping   */
                /*  track of them ...                       */
                #if OSGATHER_STATISTICS 
                OSIncTimeouts();    
                #endif
            } /* if() */
            
            /* if the tcb belongs to a cyclic timer (CT),   */
            /*  run it now with interrupts enabled. The     */
            /*  yielded bit -- which indicates if a cycTmr 	*/
            /*  is running -- is reset if the cycTmr is a 	*/ 
            /*  one-shot and is left alone if the cycTmr is	*/
            /*  continuous. One-shots are left hanging, 	*/  
            /*  continuous ones get re-enqueued. All of them*/
            /*  are executed here from within the scheduler.*/
            #if OSENABLE_CYCLIC_TIMERS
            else if ( OScTcbP->status.bits.state == OSTCB_CYCLIC_TIMER ) 
            {
            
		        OSSuspendCriticalSection();
		        OScTcbP->tFP();
		        OSResumeCriticalSection();
            
            	if ( OScTcbP->status.bits.prio == OSCT_ONE_SHOT )
            	{
	            	OScTcbP->status.bits.yielded = FALSE;
            	}
            	else
            	{
             		OScTcbP->dly.delay = OScTcbP->u.period;
             		OSInsDelay(OScTcbP);
         	  	}
         	  	
            } /* else if */
            #endif
            
            /* this is the case for tasks whose delays      */
            /*  expire and that were not waiting with a     */
            /*  timeout (they're OSTCB_TASK_ELIGIBLE).      */
            else
                OSInsElig(OScTcbP);
                
            #endif /* #if !OSENABLE_TIMEOUTS */    
    
    
        #if OSUSE_ARRAYS
            }
        #endif
    
    
        /* update handle for next round ...                 */
        #if OSUSE_ARRAYS
        OScTcbP = nextTcbP;
        #else
        OScTcbP = OSdelayQP;
        #endif
        
        
        /* let interrupts in, as we're already committed to */
        /*  plucking all tasks with expired delays from the */
        /*  delay queue. This is what v2.1's SuperTimer was */
        /*  all about ... Note that one such suspension is  */
        /*  good for both configurations (OSCOLLECT_LOST_-  */
        /*  TICKS or not).                                  */
        OSSuspendCriticalSection();
        OSResumeCriticalSection();
    
        } /* while( ) */
        
    } /* while() or if () */

    #endif /* #if OSENABLE_DELAYS */
    
    
    /********************************************************/
    /* now that delayed tasks have been processed,          */
    /*  we're ready to dispatch the most eligible           */
    /*  task ...                                            */
        
    /* array-based approach ...                             */
    /* grab tcb at head of priority queue and remove        */
    /*  the most eligible tcb from the eligible             */
    /*  queue.                                              */    
    #if OSUSE_ARRAYS
    OScTcbP = OSRtnTcbPfmA(OSeligQP);
    if ( OScTcbP ) {
        
        #if OSOPTIMIZE_FOR_SPEED
        OSeligQP &= ~OScTcbP->prioABits;
        #else
        OSDelPrio(OScTcbP, &OSeligQP);            
        #endif
    
    
    /* queue-based approach ...                             */
    /* grab tcb at head of priority queue.                  */
    /* grab tcb at head of priority queue and remove        */
    /*  the most eligible tcb from the eligible             */
    /*  queue. OSeligQP advances automatically.             */    
    /*  Reset pointers if required.                         */
    #else
    OScTcbP = OSeligQP;            
    if ( OScTcbP ) 
    {
        
        OSeligQP = OSeligQP->nextTcbP;
         
        #if OSCLEAR_UNUSED_POINTERS
        OScTcbP->nextTcbP = NULL;
        #endif
                 
    #endif /* #if OSUSE_ARRAYS */ 
     
        /* tasks in the eligible queue are either           */
        /*  OSTCB_TASK_ELIGIBLE, OSTCB_TASK_SIGNALED or 	*/
        /*  OSTCB_TASK_WAITING_TO.							*/
        /*  I.e. they got there through normal operation,   */
        /*  or because they were waiting an event and the   */
        /*  event was signaled, or they waited an event with*/
        /*  a timeout and it was never signaled (timed out).*/
        /*  We'll save the current status in                */
        /*  OScTcbP->runStatus so that task status and      */
        /*  priority info is available while running.       */
        /* runStatus gives us a "picture" of the task's     */
        /*  state and priority prior to resuming execution. */
        /*  It's used to detect, for example, whether the   */
        /*  task timed out before resuming operation.       */
        /*  runStatus is "read-only" to the current task.   */
        #if OSENABLE_TIMEOUTS
        OScTcbP->u.runStatus = OScTcbP->status.bits;    
        #endif

        /* we must mark task's call depth here, while ints  */
        /*  are still disabled.                             */
        OSIncCallDepth();     
        
        
        /* start / resume task. Get there indirectly through*/
        /*  a function pointer -- for certain distributions,*/
        /*  the call-by-pointer is implementation-dependent.*/ 
        
        /* tasks run with interrupts enabled.				*/
        OSSuspendCriticalSection();
        
	    /* this hook is here so that analysis can be done on*/
	    /*  the dispatching part of the scheduler. It's not */
	    /*  intended for general use.                       */
	    #if OSENABLE_OSSCHED_DISPATCH_HOOK
	    OSSchedDispatchHook();
	    #endif
        
        /* dispatch the task according to the method used.	*/
		#if ( (OSCTXSW_METHOD == OSVIA_OSDISPATCH) \
		  ||  (OSCTXSW_METHOD == OSVIA_OSDISPATCH_WLABEL) )
        OSDispatch();
        #else
        OScTcbP->tFP();
        #endif
        
        /* this label is used by some implementations of the*/
        /* Salvo context switcher.                          */
OSSCHED_RETURN_LABEL();
        #if (OSCTXSW_METHOD == OSRTNADDR_IS_VAR)
        OSSaveRtnAddr();
        #endif

        /* task returns to scheduler here in one of the following     */
        /*  states due to a context switch:                           */
        /*   OSTCB_TASK_ELIGIBLE     (task ran)                       */
        /*   OSTCB_DESTROYED         (task ran, destroyed itself)     */
        /*   OSTCB_TASK_STOPPED      (task ran, stopped itself)       */
        /*   OSTCB_TASK_DELAYED      (task ran, delayed itself)       */
        /*   OSTCB_TASK_WAITING      (task ran, is waiting for an     */
        /*                             event)                         */
        /*   OSTCB_TASK_WAITING_TO   (OSTCB_TASK_WAITING, with an     */
        /*                             optional timeout)              */
        /* since an event can be signaled from an interrupt, tasks    */
        /*  which are now OSTCB_TASK_WAITING and OSTCB_TASK_WAITING_TO*/
        /*  arrive here with interrupts disabled. This prevents the   */
        /*  interrupt from sneaking in and changing the task's tcb    */
        /*  before we have a chance to process it.                    */
        /* Note: Context switch has redefined the task's "resume      */
        /*  address."                                                 */        

        /* the RUNNING bit needs to be reset, and any eligible        */
        /*  task must be reenqueued into the eligible queue. Also,    */
        /*  we had a context switch, so let's log that.               */

        /* this hook is called after every context switch. It's not   */
        /*  intended for general use. It is _not_called when idling.  */
        /*  Interrupts remain enabled during this hook ...            */
        #if OSENABLE_OSSCHED_RETURN_HOOK
        OSSchedReturnHook();
        #endif
        
        /* now we're back into the OS, so gotta protect stuff ...     */
        OSResumeCriticalSection();
        
        /* unmark task's call depth.                                  */
        OSDecCallDepth(); 
        
        /* inc context-switch counter. */
        #if OSGATHER_STATISTICS    
        OSctxSws++;
        #endif /* #if OSGATHER_STATISTICS */
        
        if ( OScTcbP->status.bits.state == OSTCB_TASK_ELIGIBLE ) 
        {
            /* fast rescheduling applies only to queues, and only     */
            /*  affects round-robining (detrimentally). That's        */
            /*  because if TaskA() signals an event upon which        */
            /*  TaskB() is waiting, then TaskA() will be re-enqueued  */
            /*  into the eligible queue _before_ TaskB() (in the      */
            /*  signaled queue) moves to the eligible queue. This     */
            /*  is not the "expected" round-robin behavior.           */
            /* to have more "strict" round-robin behavior, the        */
            /*  current task (TaskA() above) should be added to the   */
            /*  signaled queue once it returns to the scheduler.      */
            /* unfortunately this slows down the scheduler - a lot!   */
            /* note that this is somewhat simpler than OSInsSigQ()    */
            /*  because there's no ecb involved. Note also that       */
            /*  OScTcbP->nextTcbP must be reset -- not optional!      */
            #if OSDISABLE_FAST_RESCHEDULING && OSENABLE_SIGQ
            if ( OSsigQoutP == 0 )
                OSsigQoutP          = OScTcbP; 
            else 
                OSsigQinP->nextTcbP = OScTcbP;
            OSsigQinP               = OScTcbP; 
            OSsigQinP->nextTcbP     =    NULL;
            
            #else
            /* o/wise we do fast rescheduling, which puts the        */
            /*  task (when eligible) back into the eligible queue    */
            /*  as quickly as possible.                              */
            #if OSUSE_ARRAYS && OSOPTIMIZE_FOR_SPEED
            OSeligQP |= OScTcbP->prioABits;
            #else
            OSInsPrio(OScTcbP, &OSeligQP);            
            #endif
            #endif
        }
            
    } /* if ( OScTcbP ) */
    
    
    /* there were no eligible tasks, so just run the idle function  */
    /*  (if enabled).                                               */
    else
    {
    	/* mark the fact that an idle ctxSw occurred. 				*/
        #if OSGATHER_STATISTICS && OSENABLE_COUNTS \
          && OSENABLE_IDLE_COUNTER
        OSidleCtxSws++;        
        #endif
            
        /* run the idling hook with	interrupts enabled.				*/
        #if OSENABLE_IDLING_HOOK
        OSSuspendCriticalSection(); 
        OSIdlingHook(); 
        OSResumeCriticalSection();
        #endif
        
    } /* if ( OScTcbP ) ... else */
    
    /* done -- clean up. */
    #if !OSUSE_INLINE_OSSCHED
    OSDecCallDepth();
    #endif

    OSEndCriticalSection();
}

#include <salvoscg.h>
#undef __OSSCHED_SCHED_C

#endif /* #if OSENABLE_TASKS */

