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

$Source: C:\\RCS\\d\\salvo\\src\\task2.c,v $
$Author: aek $
$Revision: 3.10 $
$Date: 2003-08-10 22:26:23-07 $

Function to stop the specified task.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS

/************************************************************ 
****                                                     ****
**                                                         **
OSStopTask(tID)

Stop the specified task.

Note: Currently only works from mainline code and tasks, not 
from within interrupts.
 
**                                                         **
****                                                     ****
************************************************************/
#if !OSUSE_ARRAYS

#define __OSSTOPTASK_TASK2_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSStopTask( OStypeTcbP tcbP )
OSMONITOR_KEYWORD_POST
{
    OStypeErr err;
            
    
    OSBeginCriticalSection();
    OSIncCallDepth();    
    														
    /* if the task's state is valid and it can successfully */
    /*  be removed from whatever queue it's in, then go     */
    /*  ahead and stop it. O/wise we can't stop the task.   */
    /* Delayed tasks can be stopped, so they must be        */
    /*  removed from OSdelayQ.                              */
    if ( OSTaskUsed(tcbP) && !OSDelTaskQ(tcbP, TRUE) ) {
        tcbP->status.bits.state = OSTCB_TASK_STOPPED;
        err = OSNOERR;
    }
    else
        err = OSERR;
    
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return err;
}

#include <salvoscg.h>
#undef __OSSTOPTASK_TASK2_C

#endif

#endif /* #if OSENABLE_TASKS */

