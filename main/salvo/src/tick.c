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

$Source: C:\\RCS\\d\\salvo\\src\\tick.c,v $
$Author: aek $
$Revision: 3.6 $
$Date: 2003-07-24 15:18:12-07 $

Functions to do with system ticks (i.e. elapsed time).

************************************************************/

#include <salvo.h>

#if OSENABLE_TICKS


/************************************************************ 
****                                                     ****
**                                                         **
OSGetTicks()

Return the current value of the system timer, in ticks.

**                                                         **
****                                                     ****
************************************************************/
#define __OSGETTICKS_TICK_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeTick OSGetTicks( void )
OSMONITOR_KEYWORD_POST
{
    OStypeTick localTicks;
    
    
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    localTicks = OStimerTicks;
    
    OSDecCallDepth();    
    OSEndCriticalSection();

    return localTicks;
}

#include <salvoscg.h>
#undef __OSGETTICKS_TICK_C

/************************************************************ 
****                                                     ****
**                                                         **
OSSetTicks()

(Re-)set the system timer, in ticks.

**                                                         **
****                                                     ****
************************************************************/
#define __OSSETTICKS_TICK_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
void OSSetTicks( OStypeTick tick )
OSMONITOR_KEYWORD_POST
{
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    OStimerTicks = tick;
    
    OSDecCallDepth();
    OSEndCriticalSection();    
}

#include <salvoscg.h>
#undef __OSSETTICKS_TICK_C

#endif /* #if OSENABLE_TICKS */
