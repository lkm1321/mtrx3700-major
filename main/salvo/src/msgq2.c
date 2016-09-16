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

$Source: C:\\RCS\\d\\salvo\\src\\msgq2.c,v $
$Author: aek $
$Revision: 3.7 $
$Date: 2003-07-24 15:18:16-07 $

Functions to read a message queue.

************************************************************/

#include <salvo.h>

#if OSENABLE_MESSAGE_QUEUES


/************************************************************ 
****                                                     ****
**                                                         **
OSReturnMsgQ(ecbP, countP, test)

Used by OSReadMsgQ() and OSTryMsgQ().

Note: Because the OSReturnXyz() funstions all have distinctly
different return types, they are independent of 
OSCOMBINE_EVENT_SERVICES.

See binsem.c and msg.c for comments. Only differences and 
details are mentioned here.

**                                                         **
****                                                     ****
************************************************************/
#if OSENABLE_EVENT_READING

#define __OSRETURNMSGQ_MSGQ2_C
#include <salvomcg.h>

#if !OSENABLE_EVENT_TRYING
OSMONITOR_KEYWORD_PRE
OStypeMsgP OSReturnMsgQ( OStypeEcbP      ecbP )
OSMONITOR_KEYWORD_POST
OSRETURNMSGQ_ATTR
#else
OSMONITOR_KEYWORD_PRE
OStypeMsgP OSReturnMsgQ( OStypeEcbP      ecbP,
                         OStypeBoolean   tryMsgQ )
OSMONITOR_KEYWORD_POST
OSRETURNMSGQ_ATTR
#endif                            
{
    OStypeMsgP msgP;
    OStypeMqcbP mqcbP;
    
    
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    /* local pointer is useful. */
    mqcbP = ecbP->event.mqcbP;
    
    /* count must be non-zero for anything to be there. */
    if ( mqcbP->count ) {
        msgP = *(mqcbP->outPP);
        
        #if OSENABLE_EVENT_TRYING
        if ( tryMsgQ ) {
            if ( ++mqcbP->outPP == mqcbP->endPP )
                mqcbP->outPP = mqcbP->beginPP;
            mqcbP->count--;

            OSMsg("OSReturnMsgQMsgP",
             OSMakeStr("message % d was available.",
               OSeID(ecbP)));
        }
        #endif
        
    }    
    /* o/wise there's nothing there ... */
    else {
        msgP = NULL;
        
        #if OSENABLE_EVENT_TRYING
        if ( tryMsgQ ) {
            OSMsg("OSReturnMsgQMsgP",
             OSMakeStr("message % d was not available.",
               OSeID(ecbP)));
        }
        #endif
    }
        
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return msgP;
}

#include <salvoscg.h>
#undef __OSRETURNMSGQ_MSGQ2_C

#endif 

#endif /* #if OSENABLE_MESSAGE_QUEUES */



