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

$Source: C:\\RCS\\d\\salvo\\src\\delay3.c,v $
$Author: aek $
$Revision: 3.7 $
$Date: 2003-07-24 15:18:19-07 $

OSGetTS(), OSSetTS(). Read and Write current task's timestamp.

************************************************************/

#include <salvo.h>

#if OSENABLE_DELAYS && OSENABLE_TICKS


/************************************************************ 
****                                                     ****
**                                                         **
OSGetTSTask(tcbP)

Returns task's timestamp.


**                                                         **
****                                                     ****
************************************************************/
#define __OSGETTSTASK_DELAY3_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
OStypeTS OSGetTSTask( OStypeTcbP tcbP )
OSMONITOR_KEYWORD_POST
{    
    OStypeTS timestamp;
    
        
    OSBeginCriticalSection();
    OSIncCallDepth();    

    timestamp = tcbP->dly.timestamp;
    
    OSDecCallDepth();    
    OSEndCriticalSection();
    
    return timestamp;
}

#include <salvoscg.h>
#undef __OSGETTSTASK_DELAY3_C


/************************************************************ 
****                                                     ****
**                                                         **
OSSetTSTask(tcbP, timestamp)

Sets task's timestamp.


**                                                         **
****                                                     ****
************************************************************/
#define __OSSETTSTASK_DELAY3_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
void OSSetTSTask( OStypeTcbP  tcbP,
                  OStypeTS    timestamp )
OSMONITOR_KEYWORD_POST
{    
    OSBeginCriticalSection();
    OSIncCallDepth();    

    tcbP->dly.timestamp = timestamp;
    
    OSDecCallDepth();    
    OSEndCriticalSection();
}

#include <salvoscg.h>
#undef __OSSETTSTASK_DELAY3_C

#endif /*  #if OSENABLE_DELAYS && OSENABLE_TICKS */

