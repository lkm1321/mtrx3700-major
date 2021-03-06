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

$Source: C:\\RCS\\d\\salvo\\src\\cyclic5.c,v $
$Author: aek $
$Revision: 3.2 $
$Date: 2003-07-24 15:18:21-07 $

Functions to handle cyclic timers.

************************************************************/

#include <salvo.h>

#if OSENABLE_CYCLIC_TIMERS

/************************************************************ 
****                                                     ****
**                                                         **
OSSetCycTmrPeriod()

(Re-)set (i.e. change) a cyclic timer's period. If already 
running, the cycTmr will time out normally, and then the next
period will match the argument to OSSetCycTmrPeriod().

**                                                         **
****                                                     ****
************************************************************/
#define __OSSETCYCTMRPERIOD_CYCLIC5_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSSetCycTmrPeriod ( OStypeTcbP    tcbP,
							  OStypeDelay   period )
OSMONITOR_KEYWORD_POST                           
{
    #if OSENABLE_ERROR_CHECKING
    if ( tcbP->status.bits.state != OSTCB_CYCLIC_TIMER ) 
        OSWarnRtn("OSSetCycTmrPeriod",
          OSMakeStr("not a cyclic timer."),
            (OStypeErr) OSERR_BAD_CT);   
    #endif
    
    OSBeginCriticalSection();
    OSIncCallDepth();	
       
    /* (re-)set the cycTmr's period.					*/
    tcbP->u.period = period;
									   													
    OSDecCallDepth();    
    OSEndCriticalSection();
    OSMsgRtn("OSSetCycTmrPeriod", 
      OSMakeStr("cyclic timer %d's period changed to %d.", 
        OStID(tcbP), period), 
        (OStypeErr) OSNOERR);
}

#include <salvoscg.h>
#undef __OSSETCYCTMRPERIOD_CYCLIC5_C

#endif /* #if OSENABLE_CYCLIC_TIMERS */



