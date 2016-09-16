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
 
$Source: C:\\RCS\\d\\salvo\\src\\binsem2.c,v $
$Author: aek $
$Revision: 3.6 $
$Date: 2003-07-24 15:18:22-07 $

Functions to read a binary semaphore.

************************************************************/

#include <salvo.h>


#if OSENABLE_BINARY_SEMAPHORES


/************************************************************ 
****                                                     ****
**                                                         **
OSReturnBinSem(ecbP, test)

Used by OSReadBinSem() and OSTryBinSem().

Note: Because the OSReturnXyz() funstions all have distinctly
different return types, they are independent of 
OSCOMBINE_EVENT_SERVICES.

**                                                         **
****                                                     ****
************************************************************/
#if OSENABLE_EVENT_READING

#define __OSRETURNBINSEM_BINSEM2_C
#include <salvomcg.h>

#if !OSENABLE_EVENT_TRYING
OSMONITOR_KEYWORD_PRE
OStypeBinSem OSReturnBinSem( OStypeEcbP     ecbP )
OSMONITOR_KEYWORD_POST
OSRETURNBINSEM_ATTR
#else
OSMONITOR_KEYWORD_PRE
OStypeBinSem OSReturnBinSem( OStypeEcbP     ecbP,
                             OStypeBoolean  tryBinSem )
OSMONITOR_KEYWORD_POST
OSRETURNBINSEM_ATTR
#endif                            
{
    OStypeBinSem binSem;
    
    
    /* first-level function, so critical section must    */
    /*  be protected ...                                */
    OSBeginCriticalSection();
    OSIncCallDepth();
    
    /* get a local copy of the binsem.                    */
    binSem = ecbP->event.binSem;
    
    /* this is just like waiting the binsem, only no    */
    /*  context switch is involved.                        */
    #if OSENABLE_EVENT_TRYING
    if ( tryBinSem ) {
        if ( binSem ) {
            ecbP->event.binSem = 0;
            OSMsg("OSReturnBinSem",
             OSMakeStr("binSem % d was available.",
               OSeID(ecbP)));
        }
        else {    
            OSMsg("OSReturnBinSem",
             OSMakeStr("binSem % d was not available.",
               OSeID(ecbP)));
        }
    }
    #endif
        
    /* clean up and get out.                            */
    OSDecCallDepth();
    OSEndCriticalSection();
    
    return binSem;
}

#include <salvoscg.h>
#undef __OSRETURNBINSEM_BINSEM2_C

#endif 

#endif /* #if OSENABLE_BINARY_SEMAPHORES */

