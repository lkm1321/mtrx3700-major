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

$Source: C:\\RCS\\d\\salvo\\src\\msgq4.c,v $
$Author: aek $
$Revision: 3.4 $
$Date: 2003-07-24 15:18:16-07 $

Function to discern the number of elements in a message
queue. Created because because the pointer arithmetic
inside OSMsgQEmpty() is very expensive, cycle-wise, on targets
where the data pointer size is larger than the native register
size (e.g. PIC18 + PICC-18, OSMsgQEmoty() calls awdiv).

************************************************************/

#include <salvo.h>

#if OSENABLE_MESSAGE_QUEUES


/************************************************************ 
****                                                     ****
**                                                         **
OSMsgQCount(ecbP)

Returns: number of messages pointers already in the message 
			queue.
 
**                                                         **
****                                                     ****
************************************************************/
#define __OSMSGQCOUNT_MSGQ4_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeMsgQSize OSMsgQCount ( OStypeEcbP ecbP )
OSMONITOR_KEYWORD_POST
OSMSGQCOUNT_ATTR
{            
    OStypeMsgQSize  size;
    
    OSBeginCriticalSection();
    OSIncCallDepth();
        
    size = ecbP->event.mqcbP->count;

    OSDecCallDepth();
    OSEndCriticalSection();
    
    return size;
}

#include <salvoscg.h>
#undef __OSMSGQCOUNT_MSGQ4_C

#endif /* #if OSENABLE_MESSAGE_QUEUES */



