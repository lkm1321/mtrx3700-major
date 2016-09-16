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

$Source: C:\\RCS\\d\\salvo\\src\\task3.c,v $
$Author: aek $
$Revision: 3.7 $
$Date: 2003-08-10 22:26:23-07 $

Function to destroy the specified task.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS


/************************************************************ 
****                                                     ****
**                                                         **
OSDestroyTask(tcbP)

Destroys the specified task.

Note: Currently only works from mainline code and tasks, not 
from within interrupts.
 
**                                                         **
****                                                     ****
************************************************************/

#if !OSUSE_ARRAYS

#define __OSDESTROYTASK_TASK3_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSDestroyTask( OStypeTcbP tcbP ) 
OSMONITOR_KEYWORD_POST
{
    OStypeErr err;
            
    
    OSBeginCriticalSection();
    OSIncCallDepth();    
    														
    /* if the task's state is valid and it can successfully */
    /*  be removed from whatever queue it's in, then go     */
    /*  ahead and destroy it. O/wise it can't be destroyed. */
    /* Delayed tasks can be destroyed, so they must be      */
    /*  removed from OSdelayQ.                              */
    if ( OSTaskUsed(tcbP) && !OSDelTaskQ(tcbP, TRUE) ) {
        OSInitTcb(tcbP);
        err = OSNOERR;
    }
    else
        err = OSERR;
    
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return err;
}

#include <salvoscg.h>
#undef __OSDESTROYTASK_TASK3_C

#endif

#endif /* #if OSENABLE_TASKS */

