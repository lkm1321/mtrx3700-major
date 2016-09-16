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

$Source: C:\\RCS\\d\\salvo\\src\\tid.c,v $
$Author: aek $
$Revision: 3.2 $
$Date: 2003-07-24 15:18:24-07 $

OStID()

************************************************************/

#include <salvo.h>

#if OSENABLE_TASKS


/************************************************************ 
****                                                     ****
**                                                         **
OStID(tcbP)

Given a pointer to a task, return its task ID (1 ..
OSTASKS).

Note: does not check if task pointer is valid!

Note: this function is only used for debugging -- not a 
run-time function! Use carefully, and not from ISRs!

Returns: taskID. Cannot return an error code, therefore
          taskID of 0 is ambiguous.


**                                                         **
****                                                     ****
************************************************************/
OStypeID OStID( OStypeTcbP tcbP )
{
    char i;
    OStypeTcbP localTcbP;
    
    
    OSIncCallDepth();
    OSDecCallDepth();    
    
    if ( ( tcbP < OSTCBP(1) ) || ( tcbP > OSTCBP(OSTASKS) ) )
        return 0;
        
    else {     
        i = 1;
        localTcbP = OSTCBP(1);
        while ( localTcbP < tcbP ) {
            localTcbP++;
            i++;
        } 
        
        return (OStypeID) i;
    }
}

#endif /* #OSENABLE_TASKS */

