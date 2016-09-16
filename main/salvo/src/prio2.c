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

$Source: C:\\RCS\\d\\salvo\\src\\prio2.c,v $
$Author: aek $
$Revision: 3.3 $
$Date: 2003-07-24 15:18:15-07 $

Function to get a task's priority.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS


#if !OSUSE_ARRAYS
/************************************************************ 
****                                                     ****
**                                                         **
OSGetPrioTask()

Return the priority of the specified task. 

Used by OSGetPrio().

**                                                         **
****                                                     ****
************************************************************/
#define __OSGETPRIOTASK_PRIO_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypePrio OSGetPrioTask( OStypeTcbP tcbP )
OSMONITOR_KEYWORD_POST
OSGETPRIOTASK_ATTR
{    
    OStypePrio prio;
    
    
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    prio = tcbP->status.bits.prio;
     
    OSDecCallDepth();
    OSEndCriticalSection();

    return prio;
}

#include <salvoscg.h>
#undef __OSGETPRIOTASK_PRIO_C

#endif /* #if !OSUSE_ARRAYS */

#endif /* #if OSENABLE_TASKS */

