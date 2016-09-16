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

$Source: C:\\RCS\\d\\salvo\\src\\sem2.c,v $
$Author: aek $
$Revision: 3.6 $
$Date: 2003-07-24 15:18:14-07 $

Functions to read a counting semaphore.

************************************************************/

#include <salvo.h>

#if OSENABLE_SEMAPHORES

/************************************************************ 
****                                                     ****
**                                                         **
OSReturnSem(ecbP, test)

Used by OSReadSem() and OSTrySem().

Note: Because the OSReturnXyz() funstions all have distinctly
different return types, they are independent of 
OSCOMBINE_EVENT_SERVICES.

See binsem.c for comments. Only differences and details are
mentioned here. 

**                                                         **
****                                                     ****
************************************************************/
#if OSENABLE_EVENT_READING

#define __OSRETURNSEM_SEM2_C
#include <salvomcg.h>

#if !OSENABLE_EVENT_TRYING
OSMONITOR_KEYWORD_PRE
OStypeSem OSReturnSem( OStypeEcbP     ecbP )
OSMONITOR_KEYWORD_POST
OSRETURNSEM_ATTR
#else
OSMONITOR_KEYWORD_PRE
OStypeSem OSReturnSem( OStypeEcbP     ecbP,
                       OStypeBoolean  trySem )
OSMONITOR_KEYWORD_POST
OSRETURNSEM_ATTR
#endif                            
{
    OStypeSem sem;
    
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    sem = ecbP->event.sem;
    
    #if OSENABLE_EVENT_TRYING
    if ( trySem ) {
        if ( sem ) {
            ecbP->event.sem--;
            OSMsg("OSReturnSem",
             OSMakeStr("sem % d was available.",
               OSeID(ecbP)));
        }
        else {    
            OSMsg("OSReturnSem",
             OSMakeStr("sem % d was not available.",
               OSeID(ecbP)));
        }
    }
    #endif
        
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return sem;
}

#include <salvoscg.h>
#undef __OSRETURNSEM_SEM2_C

#endif 

#endif /* #if OSENABLE_SEMAPHORES */
