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

$Source: C:\\RCS\\d\\salvo\\src\\cyclic7.c,v $
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
OSCycTmrRunning()

Returns TRUE if the cyclic timer is running, o/wise returns
FALSE.

**                                                         **
****                                                     ****
************************************************************/
#define __OSCYCTMRRUNNING_CYCLIC7_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSCycTmrRunning ( OStypeTcbP    tcbP )
OSMONITOR_KEYWORD_POST                           
{
	OStypeErr running;


    OSBeginCriticalSection();
    OSIncCallDepth();	
    
    if ( (tcbP->status.bits.state == OSTCB_CYCLIC_TIMER ) \
      && (tcbP->status.bits.yielded == TRUE) )
    {
    	running = TRUE;
    }
    else
    {
    	running = FALSE;
   	}
									   													
    OSDecCallDepth();    
    OSEndCriticalSection();
    
    return running;
}

#include <salvoscg.h>
#undef __OSCYCTMRRUNNING_CYCLIC7_C

#endif /* #if OSENABLE_CYCLIC_TIMERS */



