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

$Source: C:\\RCS\\d\\salvo\\src\\msg2.c,v $
$Author: aek $
$Revision: 3.8 $
$Date: 2003-07-24 15:18:17-07 $

Functions to read a message.

************************************************************/

#include <salvo.h>

#if OSENABLE_MESSAGES


/************************************************************ 
****                                                     ****
**                                                         **
OSReturnMsg(ecbP, test)

Used by OSReadMsg() and OSTryMsg().

Note: Because the OSReturnXyz() funstions all have distinctly
different return types, they are independent of 
OSCOMBINE_EVENT_SERVICES.

See binsem.c for comments. Only differences and details are
mentioned here. 

**                                                         **
****                                                     ****
************************************************************/
#if OSENABLE_EVENT_READING

#define __OSRETURNMSG_MSG2_C
#include <salvomcg.h>

#if !OSENABLE_EVENT_TRYING
OSMONITOR_KEYWORD_PRE
OStypeMsgP OSReturnMsg( OStypeEcbP     ecbP )
OSMONITOR_KEYWORD_POST
OSRETURNMSG_ATTR
#else
OSMONITOR_KEYWORD_PRE
OStypeMsgP OSReturnMsg( OStypeEcbP     ecbP,
                        OStypeBoolean  tryMsg )
OSMONITOR_KEYWORD_POST
OSRETURNMSG_ATTR
#endif                            
{
    OStypeMsgP msgP;
    
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    msgP = ecbP->event.msgP;
    
    #if OSENABLE_EVENT_TRYING
    if ( tryMsg ) {
        if ( msgP ) {
            ecbP->event.msgP = NULL;
            OSMsg("OSReturnMsg",
             OSMakeStr("message % d was available.",
               OSeID(ecbP)));
        }
        else {    
            OSMsg("OSReturnMsg",
             OSMakeStr("message % d was not available.",
               OSeID(ecbP)));
        }
    }
    #endif
        
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return msgP;
}

#include <salvoscg.h>
#undef __OSRETURNMSG_MSG2_C

#endif /* if OSENABLE_EVENT_READING */

#endif /* #if OSENABLE_MESSAGES */



