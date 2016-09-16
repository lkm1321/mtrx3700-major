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

$Source: C:\\RCS\\d\\salvo\\src\\cyclic6.c,v $
$Author: aek $
$Revision: 3.2 $
$Date: 2003-07-24 15:18:20-07 $

Functions to handle cyclic timers.

************************************************************/

#include <salvo.h>

#if OSENABLE_CYCLIC_TIMERS

/************************************************************ 
****                                                     ****
**                                                         **
OSResetCycTmr()

Destroy a cyclic timer. This is done by removing it 
from the delay queue (if required) and clearing out its tcb. 

**                                                         **
****                                                     ****
************************************************************/
#define __OSRESETCYCTMR_CYCLIC6_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSResetCycTmr ( OStypeTcbP    tcbP )
OSMONITOR_KEYWORD_POST                           
{
    #if OSENABLE_ERROR_CHECKING
    if ( tcbP->status.bits.state != OSTCB_CYCLIC_TIMER ) 
        OSWarnRtn("OSResetCycTmr",
          OSMakeStr("not a cyclic timer."),
            (OStypeErr) OSERR_BAD_CT);   
    #endif
    
    OSBeginCriticalSection();
    OSIncCallDepth();	
    
    /* if it's running, remove it from the delay queue	*/
    if ( tcbP->status.bits.yielded == TRUE )
    {
		OSDelDelay(tcbP);
	}
	
	/* (re-)set the delay field to be the period		*/
	tcbP->dly.delay = tcbP->u.period;

	/* re-enqueue the cycTmr into the delay queue		*/
	tcbP->status.bits.yielded = TRUE;
	OSInsDelay(tcbP);
									   													
    OSDecCallDepth();    
    OSEndCriticalSection();
    OSMsgRtn("OSResetCycTmr", 
      OSMakeStr("cyclic timer %d reset.", OStID(tcbP)), 
        (OStypeErr) OSNOERR);
}

#include <salvoscg.h>
#undef __OSRESETCYCTMR_CYCLIC6_C

#endif /* #if OSENABLE_CYCLIC_TIMERS */



