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

$Source: C:\\RCS\\d\\salvo\\src\\cyclic.c,v $
$Author: aek $
$Revision: 3.6 $
$Date: 2003-07-24 15:18:22-07 $

Functions to handle cyclic timers.

************************************************************/

#include <salvo.h>

#if OSENABLE_CYCLIC_TIMERS

/************************************************************ 
****                                                     ****
**                                                         **
OSCreateCycTmr()

Create a cyclic timer.

Cyclic timers use tcbs, but the fields have different
meanings that when used for tasks. Status byte fields:

yielded: 0: cycTmr is not running
		 1: cycTmr is running
		 
state:   always OSTCB_CYCLIC_TIMER

prio:    0: one-shot cycTmr
		 1: continuous cycTmr

**                                                         **
****                                                     ****
************************************************************/
#define __OSCREATECYCTMR_CYCLIC_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSCreateCycTmr ( OStypeTFP     tFP, 
                           OStypeTcbP    tcbP, 
                           OStypeDelay   delay,
                           OStypeDelay   period,
                           OStypeCTMode  mode )
OSMONITOR_KEYWORD_POST                           
{
    /* punt if tcbP is clearly bad.                     */
    #if OSENABLE_BOUNDS_CHECKING
    if ( (tcbP < OSTCBP(1)) || (tcbP > OSTCBP(OSTASKS_LIMIT)) ) {
        OSWarnRtn("OSCreateCycTmr",
          OSMakeStr("task %d nonexistent or invalid.",
            OSeID(ecbP)), (OStypeErr) OSERR_BAD_P);
    }
    
    /* v7.87 PL2 and earlier PICC compilers have a      */
    /*  PIC12 bug that shows up if the bounds checking  */
    /*  above is disabled. This is a simple fix.        */
    /*  Problem happens when generating libraries.      */
    #elif OSWORKAROUND_HT_PICC_1
    if ( tcbP == 0 ) {
        OSWarnRtn("OSCreateCycTmr",
          OSMakeStr("task %d nonexistent or invalid.",
            OSeID(ecbP)), (OStypeErr) OSERR_BAD_P);
    }
    #endif
    
    #if OSENABLE_ERROR_CHECKING
    if ( (mode & ~OSDONT_START_CYCTMR) > OSCT_CONTINUOUS ) 
        OSWarnRtn("OSCreateCycTmr",
          OSMakeStr("invalid cyclic timer mode: %d.",
            mode & ~OSDONT_START_TASK), 
            (OStypeErr) OSERR_BAD_CT_MODE);
            
    if ( delay == 0 || period == 0 ) 
        OSWarnRtn("OSCreateCycTmr",
          OSMakeStr("invalid delay: %d.",
            delay), (OStypeErr) OSERR_BAD_CT_DELAY);
    #endif

    OSBeginCriticalSection();
    OSIncCallDepth();	
    
    /* initialize function pointer.                     */
    tcbP->tFP = tFP;

	/* identify what kind of tcb this is ...			*/
    tcbP->status.bits.state = OSTCB_CYCLIC_TIMER;
    
	/* set the CT mode                                  */
    tcbP->status.bits.prio = (OStypePrio) (mode & ~OSDONT_START_CYCTMR);
									
	/* set the initial and reload delays                */
    tcbP->dly.delay =  delay;
    tcbP->u.period  = period;
									
    /* and put it into the delay queue ...				*/
    if ( mode & OSDONT_START_CYCTMR ) {
	    tcbP->status.bits.yielded = FALSE;
    }    
    else {
	    tcbP->status.bits.yielded = TRUE;
		OSInsDelay(tcbP);
	}
   													
    OSDecCallDepth();    
    OSEndCriticalSection();
    OSMsgRtn("OSCreateCycTmr", 
      OSMakeStr("mode %d cyclic timer %d created with delay %d.", 
      mode, OStID(tcbP), period), 
      (OStypeErr) OSNOERR);
}

#include <salvoscg.h>
#undef __OSCREATECYCTMR_CYCLIC_C

#endif /* #if OSENABLE_CYCLIC_TIMERS */



