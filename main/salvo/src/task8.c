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

$Source: C:\\RCS\\d\\salvo\\src\\task8.c,v $
$Author: aek $
$Revision: 3.1 $
$Date: 2003-07-24 15:18:11-07 $

Task vs queue manipulation.

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS

/************************************************************ 
****                                                     ****
**                                                         **
OSInsTaskQ(tcbP)

Inserts a task into the queue(s) it's expected to be in.

Returns: OSNOERR if the insertion is successful.
         OSERR if the insertion fails.

**                                                         **
****                                                     ****
************************************************************/
OStypeErr OSInsTaskQ( OStypeTcbP tcbP )
{
    OStypeErr   err;
    OStypeState state;
    
    
    /* init is required for fall-through cases, e.g.    */
    /*  OSTCB_TASK_STOPPED.                             */
    err = OSNOERR;
    
    /* Help the compiler (esp ez8cc, which chokes on	*/
    /*  switch(tcbP->status.bits.state)) by saving    	*/
    /*  this bitfield  locally in <state>.            	*/
    state = tcbP->status.bits.state;    


    switch ( state ) {
        
        /* must insert eligible and    timed-out tasks  */
        /*  into the eligible queue.                    */
        case OSTCB_TASK_ELIGIBLE:
        case OSTCB_TASK_SIGNALED:
        case OSTCB_TASK_WAITING_TO:
            err = OSInsPrio(tcbP, &OSeligQP);
            if ( err )
                OSWarn("OSInsTaskQ",
                    OSMakeStr("could not insert task %d into eligible queue.",
                    OStID(tcbP)));                    
            break;


        /* we shouldn't be getting here ...             */    
		default:
			err = OSERR;
			break;
		
#if 0                    
        /* must remove waiting tasks from their         */
        /*  respective event queues.                    */
        /* In queue mode, we can only change the state  */
        /*  of waiting tasks if timeouts are enabled.   */
        case OSTCB_TASK_WAITING:
        case OSTCB_TASK_WAITING_TO: /* not right yet! */
            #if OSENABLE_TIMEOUTS
            err = OSInsPrio(tcbP, &(tcbP->u.ecbP->tcbP));
            if ( err )
                OSWarn("OSInsTaskQ",
                    OSMakeStr("could not insert task %d into event queue.",
                    OStID(tcbP)));                    
            #else
            OSWarn("OSInsTaskQ",
                OSMakeStr("task %d cannot be inserted into event queue.",
                tID));
            err = OSERR;
            #endif
            break;
#endif
    }
    
    return err;
}

#endif /* #if OSENABLE_TASKS */

