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
 
$Source: C:\\RCS\\d\\salvo\\src\\binsem.c,v $
$Author: aek $
$Revision: 3.10 $
$Date: 2003-07-24 15:18:23-07 $

Functions to create, wait and signal a binary semaphore.

************************************************************/

#include <salvo.h>


#if OSENABLE_BINARY_SEMAPHORES

/************************************************************ 
****                                                     ****
**                                                         **
BinSem services when OSCOMBINE_EVENT_SERVICES is FALSE. 

See also event.c for documented combined version. 

The versions herein should function identically, albeit 
without reduced call graphs.

**                                                         **
****                                                     ****
************************************************************/
#if !OSCOMBINE_EVENT_SERVICES

/************************************************************ 
** OSCreateBinSem(ecbP, binSem)                            **
************************************************************/
#define __OSCREATEBINSEM_BINSEM_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSCreateBinSem( OStypeEcbP   ecbP, 
                          OStypeBinSem binSem )
OSMONITOR_KEYWORD_POST
OSCREATEBINSEM_ATTR
{
    /* first-level function, so critical section must    */
    /*  be protected ...                                */
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    /* very simple -- just initialize all fields.        */
    ecbP->tcbP         = NULL;
    ecbP->event.binSem = (OStypeBinSem) (binSem & 0x01);
    #if OSUSE_EVENT_TYPES
    ecbP->type         = OSEV_BINSEM;
    #endif
    
    /* clean up and get out.                            */
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return OSNOERR;
}

#include <salvoscg.h>
#undef __OSCREATEBINSEM_BINSEM_C


/************************************************************ 
** OSWaitBinSem(ecbP, timeout)                             **
************************************************************/
#define __OSWAITBINSEM_BINSEM_C
#include <salvomcg.h>

#if !OSENABLE_TIMEOUTS
OSMONITOR_KEYWORD_PRE
OStypeErr OSWaitBinSem( OStypeEcbP  ecbP )
OSMONITOR_KEYWORD_POST
#else
OSMONITOR_KEYWORD_PRE
OStypeErr OSWaitBinSem( OStypeEcbP  ecbP, 
                        OStypeDelay timeout )
OSMONITOR_KEYWORD_POST
#endif
{
    union {
        OStypeErr     err;    
        OStypeBoolean avail;
    } u;
    
    
    /* first-level function, so critical section must    */
    /*  be protected ...                                */
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    /* pass info on whether or not the event is            */
    /*  available to OSWaitEvent().                        */  
    u.avail = (OStypeBoolean) ecbP->event.binSem;    
    
    /* OSWaitEvent() is the real engine here -- it        */
    /*  detects how we got here (by being OSTCB_TASK_ELIGIBLE,*/
    /*  OSTCB_TASK_SIGNALED or OSTCB_TASK_WAITING_TO) and what         */
    /*  course of action we should take. ALl it needs    */
    /*  from us is to know whether or not the event in    */
    /*  question has been signaled.                        */
    #if !OSENABLE_TIMEOUTS
    u.err = OSWaitEvent(ecbP, u.avail);
    #else
    u.err = OSWaitEvent(ecbP, u.avail, timeout);
    #endif

    /* now that we're back, we'll use the bit-wise        */
    /*  error flags that OSWaitEvent() returns in order    */
    /*  to do necessary post-processing.                */
    
    /* in the case where an event had been previously    */
    /*  signaled and now the task has waited it, we        */
    /*  must "get" the event properly.                    */
    if ( u.err & OSERR_AVAILABLE ) {
        ecbP->event.binSem = 0;
        
        OSMsg("OSWaitBinSem",
         OSMakeStr("task % d acquired binary semaphore %d.",
           OStID(OScTcbP), OSeID(ecbP)));
    }
    
    /* clean up.                                        */    
    OSDecCallDepth();
    OSEndCriticalSection();
    
    /* return to wrapper with OSWaitEvent()'s return     */
    /*  code.                                            */    
    return (u.err);
}

#include <salvoscg.h>
#undef __OSWAITBINSEM_BINSEM_C


/************************************************************ 
** OSSignalBinSem(ecbP)                                    **
************************************************************/
#define __OSSIGNALBINSEM_BINSEM_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSSignalBinSem( OStypeEcbP ecbP )
OSMONITOR_KEYWORD_POST
OSSIGNALBINSEM_ATTR
{
    union {
        OStypeErr  err;
        OStypeTcbP tcbP;
    } u;

    
    /* first-level function, so critical section must    */
    /*  be protected ...                                */
    OSBeginCriticalSection();    
    OSIncCallDepth();
    
    #if OSENABLE_BOUNDS_CHECKING
    /* punt if ecbP appears bad ...                        */
    if ( (ecbP < OSECBP(1)) || (ecbP > OSECBP(OSEVENTS_LIMIT)) ) {
        OSWarn("OSSignalBinSem",
          OSMakeStr("binary semaphore %d nonexistent or invalid.",
            OSeID(ecbP)));
            
        u.err = OSERR_BAD_P;
    }
        
    else 
    #endif
    {
        #if OSENABLE_ERROR_CHECKING && OSUSE_EVENT_TYPES    
        /* punt if event being operated on is not a        */
        /*  binsem.                                        */
        if ( ecbP->type != OSEV_BINSEM ) {
            OSWarn("OSSignalBinSem",
              OSMakeStr("event %d is not a binary semaphore.",
                OSeID(ecbP)));
                
            u.err = OSERR_EVENT_BAD_TYPE;
        }
        
        else
        #endif
        {
            #if !OSENABLE_FAST_SIGNALING
            /* with slow signaling, the binsem won't be    */
            /*  cleared until the receiving task runs.    */
            /*  Therefore we don't care if a task is    */
            /*  waiting the event or not.                */
            if ( ecbP->event.binSem ) {
                OSWarn("OSSignalBinSem",
                  OSMakeStr("binary semaphore %d already set.",
                    OSeID(ecbP)));
                    
                u.err = OSERR_EVENT_FULL;
            }
            /* just set the binsem and if a task was    */
            /*  waiting, put it into the signaled queue.*/
            else {
                ecbP->event.binSem = 1;
                
                u.tcbP = ecbP->tcbP;
                if ( u.tcbP )
                    OSInsSigQ(u.tcbP, ecbP);
                    
                u.err = OSNOERR;
            }
            
            #else
            /* this is a little different ... a binsem    */
            /*  is full only if it's set and no task is    */
            /*  waiting.                                */
            if ( !ecbP->tcbP && ecbP->event.binSem ) {
                OSWarn("OSSignalBinSem",
                  OSMakeStr("binary semaphore %d already set.",
                    OSeID(ecbP)));
                    
                u.err = OSERR_EVENT_FULL;
            }
            
            /* if a task is waiting, then put it into    */
            /*  the signaled queue, else just set the    */
            /*  binsem.                                    */
            else {
                u.tcbP = ecbP->tcbP;
                if ( u.tcbP ) {
                    OSInsSigQ(u.tcbP, ecbP);
                }
                else
                    ecbP->event.binSem = 1;
                    
                u.err = OSNOERR;
            }
            #endif /* #if !OSENABLE_FAST_SIGNALING */
        }
    }
    
    /* clean up and get out.                            */
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return (u.err);        
}

#include <salvoscg.h>
#undef __OSSIGNALBINSEM_BINSEM_C

#endif /* #if !OSCOMBINE_EVENT_SERVICES */

#endif /* #if OSENABLE_BINARY_SEMAPHORES */

