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

$Source: C:\\RCS\\d\\salvo\\src\\rpt.c,v $
$Author: aek $
$Revision: 3.16 $
$Date: 2003-07-24 15:18:25-07 $

Function to generate a human-readable "status report" of 
the tasks, events, etc.

************************************************************/

/* Temporarily modified to work (better) with Keil C51! */
/*  aek 6/27/2002 */

#include <salvo.h>


#define Disp2Spc() (printf("  "))




/* stack checking is suppressed in this module */
#if 1
#undef OSIncCallDepth
#undef OSDecCallDepth
#define OSIncCallDepth()
#define OSDecCallDepth()
#endif

#if	OSUSE_PRINTF_P_FORMAT
#define	OSPTR_FORMAT		"  %08p",		 
#else
#define	OSPTR_FORMAT		" %08Xh", (unsigned) // works for 8- and 16-bit targets	
#endif	 

#define CRLF                 "\n\r"
#define FIXED_WIDTH           1
#define VARIABLE_WIDTH        0

#if !defined(max) 
#define max(a,b)    ((a) >= (b) ? (a) : (b))
#endif

#if !defined(min)
#define min(a,b)    ((a) <= (b) ? (a) : (b)) 
#endif

void OSPrintTcbBanner( void );
void OSPrintEcbBanner( void );


const char * strOSCtxSwsWIdle = "CtxSws, total=idle+eligible:";
const char * strOSCtxSws      = "CtxSws:";

/************************************************************ 
****                                                     ****
**                                                         **
OSPrintTcbP(tcbP, flag)
 
Given a pointer to a tcb, display the tcb's number
(usually the same as the tID), a code for the NULL pointer,
or show just a blank to indicate that it's invalid or
unknown (this happens when pointers are left as orphans,
etc.). 
 
**                                                         **
****                                                     ****
************************************************************/
void OSPrintTcbP( OStypeTcbP    tcbP, 
                  OStypeBoolean fixedWidth )
{
    OStypeID i;


    OSIncCallDepth();

    /* NULL condition happens a lot ...                 */
    if ( tcbP == 0 ) {
        printf("  .");
    }
    /* see if the pointer points to a task ...             */
    else {
        i = OSTASKS;
        do {
            if ( tcbP == OSTCBP(i) ) {
                if ( fixedWidth )
                    printf("t%2u", (unsigned) i);
                else 
                    printf("t%u", (unsigned) i);
                OSDecCallDepth();
                return;
            }
        } while ( --i );
            
        /* nope, it's a bad pointer. */
        printf("   ");
    }
    
    OSDecCallDepth();
}


#if  OSENABLE_EVENTS        
void OSPrintEcbP( OStypeEcbP    ecbP, 
                  OStypeBoolean fixedWidth )
{
    OStypeID i;


    OSIncCallDepth();

    if ( ecbP == 0 )
        printf("  .");
        
    else {
        i = OSEVENTS;
        do {
            if ( ecbP == OSECBP(i) ) {
                if ( fixedWidth ) 
                    printf("e%2u", (unsigned) i);
                else 
                    printf("e%u", (unsigned) i);
                OSDecCallDepth();
                return;
            }
        } while ( --i );

        printf("   ");
    }
    
    OSDecCallDepth();
}
#endif


/************************************************************ 
****                                                     ****
**                                                         **
OSPrintTcb(tcbP)
 
Display the fields of the specified tcb.

**                                                         **
****                                                     ****
************************************************************/
void OSPrintTcb( OStypeTcbP tcbP )
{
    OStypeState state;

    OSIncCallDepth();
      
    /* Help the compiler (esp ez8cc, which chokes on	*/
    /*  switch(tcbP->status.bits.state)) by saving    	*/
    /*  this bitfield  locally in <state>.            	*/
    state = tcbP->status.bits.state;    
    
    
    /* show current task with an '*' after it.        	*/
    if ( OSTaskRunning(tcbP) ) 
        printf("* ");
    else
        printf("  ");


    /* task status (only 8 allowed values).			  	*/
    switch ( state ) {
        case OSTCB_DESTROYED:
            printf("dstr");
            break;
        case OSTCB_TASK_STOPPED:
            printf("stop");
            break;
        case OSTCB_TASK_DELAYED:
            printf("dlyd");
            break;
        case OSTCB_TASK_WAITING:
            printf("wait");
            break;
        case OSTCB_TASK_WAITING_TO:
            printf("wtto");
            break;
        case OSTCB_TASK_SIGNALED:
        case OSTCB_TASK_ELIGIBLE:
            printf("elig");
            break;
        case OSTCB_CYCLIC_TIMER:
            printf("undf");
            break;
    }
    
    /* raw dump of tcb contents.                    	*/
    /* task priority.                                	*/
    #if !OSRPT_HIDE_INVALID_POINTERS 
    printf(" %3u", (unsigned) tcbP->status.bits.prio);
    
    /* task start/resume address.                    	*/
    printf(OSPTR_FORMAT tcbP->tFP); 
    
    /* task ID of next task in priority queue.        	*/
    OSPrintTcbP(tcbP->nextTcbP, 1);    
    
    /* event ID.                                    	*/
    Disp2Spc();
    OSPrintEcbP(tcbP->u.ecbP, 1);
    
    /* delay value.                                    */
    #if   OSBYTES_OF_DELAYS == 1
    printf("  %3u   ", (unsigned) tcbP->dly.delay);
    #elif OSBYTES_OF_DELAYS == 2
    printf(" %5u  ",   (unsigned) tcbP->dly.delay);
    #elif OSBYTES_OF_DELAYS == 3
    printf(" %8u  ",   (unsigned) tcbP->dly.delay);
    #elif OSBYTES_OF_DELAYS == 4
    printf(" %11u  ",  (unsigned) tcbP->dly.delay);
    #endif 
        
    /* task ID of next task in delay queue.            */
    OSPrintTcbP(tcbP->nextDlyTcbP, 1);

    /* more readable dump of tcb contents.            */
    #else
    /* show start/resume address and priority only     */
    /*  if active.                                    */
    if ( state != OSTCB_DESTROYED ) {
        printf(" %3u", (unsigned) tcbP->status.bits.prio);
        printf(OSPTR_FORMAT tcbP->tFP); 
    }
        
    /* show next pointer only if not destroyed, and    */
    /*  event pointer only if not destroyed and        */
    /*  applicable.                                    */
    switch (state) {
        case OSTCB_DESTROYED:
            break;
        default:
            Disp2Spc(); 
            OSPrintTcbP(tcbP->nextTcbP, FIXED_WIDTH);    
            
            /* event ID */
            Disp2Spc();
            if ( state == OSTCB_TASK_ELIGIBLE )
                printf("n/a");
            else
            #if OSENABLE_EVENTS && OSENABLE_TIMEOUTS
            OSPrintEcbP(tcbP->u.ecbP, FIXED_WIDTH);
            #endif
            break;
    }

    /* waiting delay and pointers */
    switch (state) {
        case OSTCB_TASK_DELAYED:
        case OSTCB_TASK_WAITING:
        case OSTCB_TASK_WAITING_TO:
            #if OSENABLE_TIMEOUTS
            Disp2Spc();
            OSPrintTcbP(tcbP->nextDlyTcbP, FIXED_WIDTH);
            #endif
            
            #if OSENABLE_DELAYS || OSENABLE_TIMEOUTS
            #if   OSBYTES_OF_DELAYS == 1
            printf("  %3u   ", (unsigned) tcbP->dly.delay);
            #elif OSBYTES_OF_DELAYS == 2
            printf(" %5u  ",   (unsigned) tcbP->dly.delay);
            #elif OSBYTES_OF_DELAYS == 3
            printf(" %8u  ",   (unsigned) tcbP->dly.delay);
            #elif OSBYTES_OF_DELAYS == 4
            printf(" %11u  ",  (unsigned) tcbP->dly.delay);
            #endif
            #endif
            break;

        default:
            break;
    }
    #endif /* #if !OSRPT_HIDE_INVALID_POINTERS */
    
    printf(CRLF);    
    
    OSDecCallDepth();
}


/************************************************************ 
****                                                     ****
**                                                         **
OSPrintEcb(ecbP)
 
Display the fields of the specified ecb.

**                                                         **
****                                                     ****
************************************************************/
#if OSENABLE_EVENTS
void OSPrintEcb( OStypeEcbP ecbP )
{
    OStypeTcbP tcbP;


    OSIncCallDepth();

    /* separate whatever came before (e.g. eventID)     */
    /*  from the rest.                                    */    
    Disp2Spc();

    /* local handle.                                    */
    tcbP = ecbP->tcbP;  

    /* event type and value (format depends on type).     */
    #if OSUSE_EVENT_TYPES
    switch (ecbP->type) {
        case OSEV_DESTROYED:
            printf("dstr");
            break;
            
        #if OSENABLE_BINARY_SEMAPHORES
        case OSEV_BINSEM:
            printf("BSem ");
            OSPrintTcbP(tcbP, FIXED_WIDTH);    
            printf(" %8d", ecbP->event.binSem);
            break;
        #endif

        #if OSENABLE_EVENT_FLAGS
        case OSEV_EFLAG:
            printf("EFlg ");
            OSPrintTcbP(tcbP, FIXED_WIDTH);    
            printf(" %08Xh", ecbP->event.efcbP->eFlag);
            break;
        #endif

        #if OSENABLE_SEMAPHORES
        case OSEV_SEM:
            printf(" Sem ");
            OSPrintTcbP(tcbP, FIXED_WIDTH);    
            printf(" %8d", ecbP->event.sem);
            break;
        #endif    
        
        #if OSENABLE_MESSAGES
        case OSEV_MSG:
            printf(" Msg ");
            OSPrintTcbP(tcbP, FIXED_WIDTH);    
            printf(OSPTR_FORMAT ecbP->event.msgP);
            break;
        #endif
        
        #if OSENABLE_MESSAGE_QUEUES
        case OSEV_MSGQ:
            printf("MsgQ ");
            OSPrintTcbP(tcbP, FIXED_WIDTH);    
            printf(OSPTR_FORMAT *(ecbP->event.mqcbP->outPP));
            printf("  count: %d", ecbP->event.mqcbP->count);
            break;
        #endif
        
        default:
            printf(" ERR ");
            break;
    }
    
    
    /* raw display of event type and value.                */
    #else
    
    #if OSRPT_HIDE_INVALID_POINTERS 
    if ( ecbP->type != OSEV_DESTROYED ) {
    #endif
    
        OSPrintTcbP(ecbP->tcbP, FIXED_WIDTH);    
 //       printf(" %4xh", (unsigned) ecbP->event.sem);
        printf(" %4xh", ecbP->event.sem);
        
    #if OSRPT_HIDE_INVALID_POINTERS 
    }
    #endif
    
    #endif /* #if OSUSE_EVENT_TYPES */
        
    printf(CRLF);    
    
    OSDecCallDepth();
}
#endif


/************************************************************ 
****                                                     ****
**                                                         **
OSPrintEcbBanner()
OSPrintTcbBanner()

Simple banners to be placed above ecb/tcb display.

**                                                         **
****                                                     ****
************************************************************/
void OSPrintTcbBanner( void )
{      
    /* banner for tasks.                                */
    printf(CRLF "task stat prio    addr   t->  e->");
    
    #if OSENABLE_DELAYS && OSENABLE_TIMEOUTS
    printf("  d-> delay" CRLF);
    #elif OSENABLE_DELAYS && !OSENABLE_TIMEOUTS
    printf("delay" CRLF);
    #else
    printf(CRLF);
    #endif
}    


#if OSENABLE_EVENTS
void OSPrintEcbBanner( void )
{    
    /* banner for events.                                */
    #if OSUSE_EVENT_TYPES
    printf(CRLF "evnt type t->    value" CRLF);
    #else
    printf(CRLF "evnt t->    value" CRLF);
    #endif
}
#endif


/************************************************************ 
****                                                     ****
**                                                         **
OSRpt()

Display the status of the system, in a manner suitable for
viewing on a conventional 80-char-wide terminal screen.

**                                                         **
****                                                     ****
************************************************************/
void OSRpt( void )
{
    union {
        OStypeID    i;
        
        #if OSENABLE_DELAYS || OSENABLE_TIMEOUTS
        OStypeDelay delay;
        #endif
    } u1;
    OStypeTcbP  tcbP;
    
    
    
    OSIncCallDepth();
    
    /* version string.                                    */
    printf(CRLF "Salvo %c.%c.%c  ", 
      '0' + OSVER_MAJOR,
      '0' + OSVER_MINOR,
      '0' + OSVER_SUBMINOR);
    /* used stack depth.                                */
    #if OSENABLE_STACK_CHECKING
    printf("Max call...rtn stack depth: %u", OSmaxStkDepth);
    #endif
            
    /* number of context switches.                         */
    #if OSGATHER_STATISTICS && OSENABLE_COUNTS
     
     #if OSENABLE_IDLE_COUNTER
     
      #if ( OSBYTES_OF_COUNTS <= 2 )
    printf(CRLF "%s %u = %u + %u", strOSCtxSwsWIdle,
      OSctxSws+OSidleCtxSws, OSidleCtxSws, OSctxSws);
      #elif ( OSBYTES_OF_COUNTS <= 4 ) 
    printf(CRLF "%s %lu = %lu + %lu", strOSCtxSwsWIdle,
      OSctxSws+OSidleCtxSws, OSidleCtxSws, OSctxSws);
      #endif
      
     #else
     
      #if ( OSBYTES_OF_COUNTS <= 2 )
    printf(CRLF "%s %u", strOSCtxSws, OSctxSws);
    #elif ( OSBYTES_OF_COUNTS <= 4 )
    printf(CRLF "%s %lu", strOSCtxSws, OSctxSws);
    #endif 
    
    #endif 
    
    #endif


    /* display system information.                         */
    #if OSLOGGING && !OSGATHER_STATISTICS
    printf(CRLF "Errors: %u  Warnings: %u  ",
      OSerrs, OSwarns);   
    #endif
    
    #if !OSLOGGING && OSGATHER_STATISTICS && OSENABLE_TIMEOUTS
    printf(CRLF "Timeouts: %u  ", 
      OStimeouts);   
    #endif
    
    #if OSLOGGING && OSGATHER_STATISTICS && OSENABLE_TIMEOUTS
    printf(CRLF "Errors: %u  Warnings: %u  Timeouts: %u  ",
      OSerrs, OSwarns, OStimeouts);   
    #endif
    
 
      /* always show ticks.                                 */
    #if OSENABLE_TICKS 
    #if OSBYTES_OF_TICKS <= 2 
    printf("Ticks: %u", OStimerTicks);
    #else
    printf("Ticks: %lu", OStimerTicks);
    #endif
    #endif


    /* show eligible queue. tcbP test prevents runaway    */
    /*  pointers from indefinitely extending this loop.    */    
    printf(CRLF "EligQ: ");
    tcbP = OSeligQP;
    #if !OSENABLE_ERROR_CHECKING
    while ( tcbP ) {
    #else
    while ( ( tcbP ) && ( tcbP <= OSTCBP(OSTASKS) ) ) {
    #endif
        OSPrintTcbP(tcbP, VARIABLE_WIDTH);
        if ( tcbP->status.bits.state == OSTCB_TASK_WAITING_TO )
          printf("(t)");
        tcbP = tcbP->nextTcbP;
        if ( tcbP )
            printf(",");            
    }

      
    /* show delay queue. Compute total delay of tasks    */
    /*  in queue.                                        */
    #if OSENABLE_DELAYS || OSENABLE_TIMEOUTS
    printf(CRLF "DelayQ: ");
    u1.delay = 0;
    tcbP = OSdelayQP;
    #if !OSENABLE_ERROR_CHECKING
    while ( tcbP ) {
    #else
    while ( ( tcbP ) && ( tcbP <= OSTCBP(OSTASKS) ) ) {
    #endif
        OSPrintTcbP(tcbP, VARIABLE_WIDTH);
        u1.delay += tcbP->dly.delay;
        
        #if !OSENABLE_TIMEOUTS    
        tcbP = tcbP->nextTcbP;
        #else
        tcbP = tcbP->nextDlyTcbP;
        #endif
        
        if ( tcbP )
            printf(",");
    }
    if ( u1.delay )
        printf("  Total delay: %u ticks", u1.delay);
    #endif
    

    /* Now show the actual tcbs.                        */
    OSPrintTcbBanner();
    for ( u1.i = 1 ; u1.i <= OSTASKS ; ++u1.i ) {
    
        #if OSRPT_SHOW_ONLY_ACTIVE 
        if ( (OSTCBP(u1.i))->status.bits.state != OSTCB_DESTROYED ) {
        #endif
        
            printf(" %2u", (unsigned) u1.i);
            OSPrintTcb(OSTCBP(u1.i));
            
        #if OSRPT_SHOW_ONLY_ACTIVE 
        }
        #endif
    }
    
    
    /* Now show the actual ecbs.                        */
    #if OSENABLE_EVENTS
    OSPrintEcbBanner();
    for ( u1.i = 1 ; u1.i <= OSEVENTS ; ++u1.i ) {
        printf(" %2u", (unsigned) u1.i);
        OSPrintEcb(OSECBP(u1.i));
    }
    #endif

    OSDecCallDepth();
}
 
