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

$Source: C:\\RCS\\d\\salvo\\src\\msg.c,v $
$Author: aek $
$Revision: 3.9 $
$Date: 2003-07-24 15:18:17-07 $

Functions to create, wait and signal a message.

************************************************************/

#include <salvo.h>

#if OSENABLE_MESSAGES


/************************************************************ 
****                                                     ****
**                                                         **
Msg services when OSCOMBINE_EVENT_SERVICES is FALSE. 

See event.c for fully documented version. The versions 
herein should function identically, albeit without reduced
call graphs.

**                                                         **
****                                                     ****
************************************************************/
#if !OSCOMBINE_EVENT_SERVICES

/************************************************************ 
** OSCreateMsg(ecbP, msgP)                                 **
************************************************************/
#define __OSCREATEMSG_MSG_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSCreateMsg( OStypeEcbP ecbP, 
                       OStypeMsgP msgP )
OSMONITOR_KEYWORD_POST
OSCREATEMSG_ATTR
{
    OSBeginCriticalSection();
    OSIncCallDepth();

    ecbP->tcbP       = NULL;
    ecbP->event.msgP = msgP;
    #if OSUSE_EVENT_TYPES
    ecbP->type       = OSEV_MSG;
    #endif
    
    
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return OSNOERR;
}

#include <salvoscg.h>
#undef __OSCREATEMSG_MSG_C


/************************************************************ 
** OSWaitMsg(ecbP, msgPP, timeout)                         **
************************************************************/
#define __OSWAITMSG_MSG_C
#include <salvomcg.h>

#if !OSENABLE_TIMEOUTS
OSMONITOR_KEYWORD_PRE
OStypeErr OSWaitMsg( OStypeEcbP  ecbP, 
                     OStypeMsgPP msgPP )
OSMONITOR_KEYWORD_POST
#else
OSMONITOR_KEYWORD_PRE
OStypeErr OSWaitMsg( OStypeEcbP  ecbP, 
                     OStypeMsgPP msgPP, 
                     OStypeDelay timeout )
OSMONITOR_KEYWORD_POST
#endif
{
    union {
        OStypeErr     err;            
        OStypeBoolean avail;
    } u;
    
    
    OSBeginCriticalSection();
    OSIncCallDepth();    

    
    u.avail = FALSE;
    if ( ecbP->event.msgP != (OStypeMsgP) 0 )
        u.avail++;
    
    #if !OSENABLE_TIMEOUTS
    u.err = OSWaitEvent(ecbP, u.avail);
    #else
    u.err = OSWaitEvent(ecbP, u.avail, timeout);
    #endif
    
    /* when fast signaling, the message pointer was         */
    /*  copied to the task's tcb msgP field when the         */
    /*  message was signaled. Now, pass it "up" to the        */
    /*  calling task. Note that not only must fast signaling*/
    /*  be enabled, but the task must have been made         */
    /*  by the signaling for this to take place.            */        
    #if OSENABLE_FAST_SIGNALING
    if ( u.err & OSERR_SIGNALED ) {
        *msgPP = OScTcbP->msgP;
        
        #if OSCLEAR_UNUSED_POINTERS
        OScTcbP->msgP = NULL;
        #endif
        
        OSMsg("OSWaitMsg",
         OSMakeStr("task % d acquired message %d (now %d).",
           OStID(OScTcbP), OSeID(ecbP), OScTcbP->msgP));
    }
    else 
    #endif
    
    /* if the message had already been signaled before the    */
    /*  task waited the message, then the message is stored    */
    /*  in the ecb, and we need to get it from there. In    */
    /*  this case, the message MUST be cleared, o/wise it    */
    /*  would persist indefinitely.                            */
    if ( u.err & OSERR_AVAILABLE ) {
        *msgPP = ecbP->event.msgP;
        ecbP->event.msgP = NULL;
        
        OSMsg("OSWaitMsg",
         OSMakeStr("task % d acquired message %d (now %d).",
           OStID(OScTcbP), OSeID(ecbP), ecbP->event.msgP));
    }
    
    /* lastly, the task may simply have timed out waiting    */
    /*  for the event.  In that case, the local msgP must    */
    /*  be cleared.                                            */
    else {
        if ( u.err & OSERR_TIMEOUT )
            *msgPP = NULL;
    }
        
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return (u.err);
}

#include <salvoscg.h>
#undef __OSWAITMSG_MSG_C

/************************************************************ 
** OSSignalMsg(ecbP, msgP)                                 **
************************************************************/
#define __OSSIGNALMSG_MSG_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeErr OSSignalMsg( OStypeEcbP ecbP, 
                       OStypeMsgP msgP )
OSMONITOR_KEYWORD_POST
OSSIGNALMSG_ATTR
{
    union {
        OStypeErr  err;
        OStypeTcbP tcbP;
    } u;

    
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    #if OSENABLE_BOUNDS_CHECKING
    if ( (ecbP < OSECBP(1)) || (ecbP > OSECBP(OSEVENTS_LIMIT)) ) {
        OSWarn("OSSignalMsg",
          OSMakeStr("message %d nonexistent or invalid.",
            OSeID(ecbP)));
            
        u.err = OSERR_BAD_P;
    }
        
    else 
    #endif
    {
        #if OSENABLE_ERROR_CHECKING && OSUSE_EVENT_TYPES
        if ( ecbP->type != OSEV_MSG ) {
            OSWarn("OSSignalMsg",
              OSMakeStr("event %d is not a message.",
                OSeID(ecbP)));
                
            u.err = OSERR_EVENT_BAD_TYPE;
        }
        else
        #endif
        {    
            #if !OSENABLE_FAST_SIGNALING
            /* in the slow signaling case, we can't do         */
            /*  anything until a task picks up the existing    */
            /*  message.                                    */
            if ( ecbP->event.msgP ) {
                OSWarn("OSSignalMsg",
                  OSMakeStr("message %d already present.",
                    OSeID(ecbP)));
                
                u.err = OSERR_EVENT_FULL;
            }
            
            /* the message pointer is stored in the ecb,    */
            /*  the waiting task (if any) is made eligible    */
            /*  so that it can get the message when it runs.*/
            else {
                ecbP->event.msgP = msgP;
                
                u.tcbP = ecbP->tcbP;
                if ( u.tcbP )
                    OSInsSigQ(u.tcbP, ecbP);
                
                u.err = OSNOERR;    
            }
            
            #else
            /* in the fast signaling case, a message is     */
            /*  waiting only if there's no task waiting the    */
            /*  message.                                    */
            if ( !ecbP->tcbP && ecbP->event.msgP ) {
                OSWarn("OSSignalMsg",
                  OSMakeStr("message %d already present.",
                    OSeID(ecbP)));
                
                u.err = OSERR_EVENT_FULL;
            }
            
            /* o/wise either launch the waiting task, with    */
            /*  the msgP in its tcb, or just copy the msgP    */
            /*  to the ecb.                                    */
            else {
                u.tcbP = ecbP->tcbP;
                if ( u.tcbP ) {
                    OSInsSigQ(u.tcbP, ecbP);
                    u.tcbP->msgP = msgP;
                }
                else
                    ecbP->event.msgP = msgP;
                
                u.err = OSNOERR;    
            }
            #endif
        }
    }
    
    OSDecCallDepth();
    OSEndCriticalSection();    
    
    return(u.err);    
}

#include <salvoscg.h>
#undef __OSSIGNALMSG_MSG_C


#endif /* #if !OSCOMBINE_EVENT_SERVICES */

#endif /* #if OSENABLE_MESSAGES */



