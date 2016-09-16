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

$Source: C:\\RCS\\d\\salvo\\src\\prio.c,v $
$Author: aek $
$Revision: 3.8 $
$Date: 2003-07-24 15:18:16-07 $

Function to change a task's priority.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS


#if !OSUSE_ARRAYS
/************************************************************ 
****                                                     ****
**                                                         **
OSSetPrio(prio)

Set the current task's priority.
 
Note: A context switch following OSSetPrio() is not required,
but the effect of changing the priority will not take
effect until the next trip through the scheduler. Hence
only OS_SetPrio() should be used in order to avoid confusion.

Note: Since the current task is running, there's no need
to worry about event queues, etc.  The task will be
re-enqueued into the eligible queue when it returns to the
scheduler.

**                                                         **
****                                                     ****
************************************************************/
#if !OSDISABLE_TASK_PRIORITIES

#define __OSSETPRIO_PRIO_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
void OSSetPrio( OStypePrio prio )
OSMONITOR_KEYWORD_POST
{
    
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    /* assign new priority to task */
    #if OSENABLE_ERROR_CHECKING
    OSInitPrioTask(OScTcbP, prio);

    #else
    OScTcbP->status.bits.prio = prio;

    #endif

    OSDecCallDepth();
    OSEndCriticalSection();
}

#include <salvoscg.h>
#undef __OSSETPRIO_PRIO_C

#endif

#endif /* #if !OSUSE_ARRAYS */

#endif /* #if OSENABLE_TASKS */

