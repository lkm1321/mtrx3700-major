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

$Source: C:\\RCS\\d\\salvo\\src\\eid.c,v $
$Author: aek $
$Revision: 3.2 $
$Date: 2003-07-24 15:18:28-07 $

OSeID()

************************************************************/

#include <salvo.h>


/************************************************************ 
****                                                     ****
**                                                         **
OSeID(ecbP)

Given a pointer to an event, return its event ID (1 ..
OSEVENTS).

Note: does not check if event pointer is valid!

Note: this function is only used for debugging -- not a 
run-time function!

**                                                         **
****                                                     ****
************************************************************/
#if OSLOGGING && (OSLOG_MESSAGES > OSLOG_NONE)

OStypeID OSeID( OStypeEcbP ecbP )
{
    OStypeID i;
    OStypeEcbP localEcbP;
    
    OSIncCallDepth();
     
    i = 0;
    localEcbP = OSecbArea;
    while ( localEcbP < ecbP ) {
        localEcbP++;
        i++;
    } 
    
    OSDecCallDepth();    

    return i;
}

#endif /* #if OSLOGGING etc. */



