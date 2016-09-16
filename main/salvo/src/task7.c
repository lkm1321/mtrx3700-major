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

$Source: C:\\RCS\\d\\salvo\\src\\task7.c,v $
$Author: aek $
$Revision: 3.9 $
$Date: 2003-07-24 15:18:24-07 $

Task vs queue manipulation.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS

/************************************************************ 
****                                                     ****
**                                                         **
OSTaskUsed(tcbPP)

Find out if a task is actually in use.

Returns: TRUE if the tcbP is valid and the task has
          a valid task state (other than destroyed or undef)
         FALSE if the tcbP is bad or if the task is
          destroyed or undef

**                                                         **
****                                                     ****
************************************************************/
OStypeErr OSTaskUsed ( OStypeTcbP tcbP )
{
    OStypeErr taskUsed;
    OStypeState state;
    
    
    OSIncCallDepth();
    
    /* punt if bad. */
    #if OSENABLE_ERROR_CHECKING
    if ( tcbP == 0 ) {
        OSWarn("OSStopTask",
            OSMakeStr("task %d does not exist or is invalid.",
            tID));
            
        taskUsed = FALSE;
    }
    
    else 
    #endif 
    {
        /* keep a local handle to speed things up.                */
        state = tcbP->status.bits.state;
        
        /* can't stop these types of tasks, i.e. if the tcb is    */
        /*  either blank or in use as a cyctmr, then this tcb	  */
        /*  does not represent a task that can be stopped.        */
        if ( ( state == OSTCB_DESTROYED ) || ( state == OSTCB_CYCLIC_TIMER ) ) {
          
            OSWarn("OSTaskUsed",
                OSMakeStr("cannot operate on task %d.",
                tID));
          
            taskUsed = FALSE;
        }
        else
            taskUsed = TRUE;
    }
    
    OSDecCallDepth();
    
    return taskUsed;
}


/************************************************************ 
****                                                     ****
**                                                         **
OSDelTaskQ(tcbP, flag)

Removes a task from the queue(s) it's in. If flag is TRUE,
delayed tasks are removed from OSdelayQ. If FALSE, they're
left in there.

Returns: OSNOERR if the removal is successful.
         OSERR if the removal fails.

**                                                         **
****                                                     ****
************************************************************/
OStypeErr OSDelTaskQ( OStypeTcbP    tcbP,
                      OStypeBoolean delDelayedTask )
{
    OStypeErr   err;
    OStypeState state;
    
    
    /* init is required for fall-through cases, e.g.    */
    /*  OSTCB_TASK_STOPPED.                             */
    err = OSNOERR;
    
      
    /* Help the compiler (esp ez8cc, which chokes on	*/
    /*  switch(tcbP->status.bits.state)) by saving    	*/
    /*  this bitfield  locally in <state>.            	*/
    state = tcbP->status.bits.state;    


    switch ( state ) 
    {
        
        /* must remove eligible and timed-out tasks     */
        /*  from the eligible queue.                    */
        case OSTCB_TASK_ELIGIBLE:
        case OSTCB_TASK_SIGNALED:
        case OSTCB_TASK_WAITING_TO:
            err = OSDelPrio(tcbP, &OSeligQP);
            if ( err )
            {
                OSWarn("OSDelTaskQ",
                    OSMakeStr("task %d not in eligible queue.",
                    OStID(tcbP)));  
            }                  
            break;
        
        
        /* in some cases, we want to remove tasks from  */
        /*  OSdelayQ (e.g. when stopping a task). But   */
        /*  in other cases (e.g. when changing a task's */
        /*  priority) this is unnecessary.              */    
        case OSTCB_TASK_DELAYED:
            if ( delDelayedTask )
            {
		        #if OSENABLE_DELAYS
		        
                #if !OSENABLE_TIMEOUTS
                err = OSDelPrio(tcbP, &OSdelayQP);
                #else    
                err = OSDelDelay(tcbP);   
                #endif
                
	            if ( err )
	                OSWarn("OSDelTaskQ",
	                    OSMakeStr("task %d not in delay queue.",
	                    OStID(tcbP)));       
	                                 
                #else /* #if OSENABLE_DELAYS */
                
                err = OSERR;
                OSWarn("OSDelTaskQ",
                    OSMakeStr("task %d cannnot be in delay queue.",
                    OStID(tcbP)));                    
                    
                #endif /* #if OSENABLE_DELAYS #else ... */
            }
            else
            {
            	;
            }
            break;


        /* we shouldn't be getting here ...             */    
		default:
			err = OSERR;
			break;
		
        
#if 0            
        /* must remove waiting tasks from their         */
        /*  respective event queues.                    */
        /* In queue mode, we can only change the state  */
        /*  of waiting tasks if timeouts are enabled.   */
        case OSTCB_TASK_WAITING:
        case OSTCB_TASK_WAITING_TO: /* not right yet! */
            #if OSENABLE_TIMEOUTS
            err = OSDelPrio(tcbP, &(tcbP->u.ecbP->tcbP));
            if ( !err )
                err = OSInsPrioQ(tcbP, &(tcbP->u.ecbP->tcbP));
            else
                OSWarn("OSDelTaskQ",
                    OSMakeStr("task %d not in event queue.",
                    OStID(tcbP)));                    
            #else
            OSWarn("OSDelTaskQ",
                OSMakeStr("task %d cannot be removed from event queue.",
                tID));
            err = OSERR;
            #endif
            break;
#endif
    }
    
    return err;
}
    
#endif /* #if OSENABLE_TASKS */

