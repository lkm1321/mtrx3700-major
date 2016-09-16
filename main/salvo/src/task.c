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

$Source: C:\\RCS\\d\\salvo\\src\\task.c,v $
$Author: aek $
$Revision: 3.9 $
$Date: 2003-07-24 15:18:14-07 $

Function to manipulate a specified task.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS


/************************************************************ 
****                                                     ****
**                                                         **
OSStartTask(tcbP)

Start a task. Task must have been created beforehand via 
OSCreateTask(), and should be OSTCB_TASK_STOPPED. The task will 
execute from the scheduler once it becomes the highest-
priority eligible task.

Returns:     OSNOERR if successful
            OSERR if specified task doesn't exist

**                                                         **
****                                                     ****
************************************************************/
#define __OSSTARTTASK_TASK_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSStartTask( OStypeTcbP tcbP )
OSMONITOR_KEYWORD_POST
OSSTARTTASK_ATTR
{
    /* start stack checking. */
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    /* punt if tcbP is clearly bad.                         */
    #if OSENABLE_BOUNDS_CHECKING
    if ( (tcbP < OSTCBP(1)) || (tcbP > OSTCBP(OSTASKS_LIMIT)) ) {
        OSWarnRtn("OSStartTask",
          OSMakeStr("task %d nonexistent or invalid.",
            OSeID(ecbP)), (OStypeErr) OSERR_BAD_P);
    }
    #endif
    
    /* tcbP must be valid and task must be             */
    /*  initialized properly or it can't be made    */
    /*  ready.                                        */
    if ( tcbP->status.bits.state != OSTCB_TASK_STOPPED ) {
        OSDecCallDepth();
        OSEndCriticalSection();    
        OSWarnRtn("OSStartTask", 
          OSMakeStr("unable to start task %d.", OStID(tcbP)), 
          (OStypeErr) OSERR);
    }
  
    /* make task OSTCB_TASK_ELIGIBLE and enqueue it into     */
    /*  signaled queue.                                */
    #if OSCALL_OSSTARTTASK == OSFROM_BACKGROUND
    OSInsElig(tcbP);
    #else
    tcbP->status.bits.state = OSTCB_TASK_ELIGIBLE;
    if ( !OSsigQinP ) 
      OSsigQoutP            = tcbP;
    else
      OSsigQinP->nextTcbP   = tcbP;
    OSsigQinP               = tcbP;
    tcbP->nextTcbP          = NULL;
    #endif
    
    /* finish stack checking. */
    OSDecCallDepth();
    OSEndCriticalSection();
    
    /* success, task was started. */
    return OSNOERR;
}

#include <salvoscg.h>
#undef __OSSTARTTASK_TASK_C

#endif /* #if OSENABLE_TASKS */

