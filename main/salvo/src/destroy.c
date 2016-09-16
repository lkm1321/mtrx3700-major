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

$Source: C:\\RCS\\d\\salvo\\src\\destroy.c,v $
$Author: aek $
$Revision: 3.8 $
$Date: 2003-07-24 15:18:19-07 $

Functions to destroy a task.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS

/************************************************************ 
****                                                     ****
**                                                         **
OSDestroy()

Destroy the current task.

Note: Context switch immediately after OSDestroy()!

Note: The task's tcbP will be redefined when the task
returns to the Scheduler, but since it's OSTCB_DESTROYED,
that pointer is invalid anyway.

**                                                         **
****                                                     ****
************************************************************/
#define __OSDESTROY_DESTROY_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
void OSDestroy( void )
OSMONITOR_KEYWORD_POST
{
    OSBeginCriticalSection();
    OSIncCallDepth();										
        													
    /* force the task to be OSTCB_DESTROYED.             */
    /* in Power C implementations, we can't just        */
    /*  re-initialize the tcb because doing so clears 	*/
    /*  ctxSwVect, which is used in the POWERC environ- */
    /*  ment by OSCtxSw() to determine how to massage   */
    /*  the PC's stack in order to return all the way   */
    /*  to the scheduler correctly.                     */
    OScTcbP->status.bits.state = OSTCB_DESTROYED;

    OSDecCallDepth();
    OSEndCriticalSection();
}

#include <salvoscg.h>
#undef __OSDESTROY_DESTROY_C

#endif /* #if OSENABLE_TASKS */



