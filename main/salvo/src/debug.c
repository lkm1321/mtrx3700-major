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

$Source: C:\\RCS\\d\\salvo\\src\\debug.c,v $
$Author: aek $
$Revision: 3.2 $
$Date: 2003-07-24 15:18:28-07 $

Functions for printf-type debugging.

************************************************************/

#include <salvo.h>


/************************************************************ 
****                                                     ****
**                                                         **
OSMakeStr() 
                                                   
Function which allows the passing of printf-style variable
argument lists for reporting purposes. This is used to
generate useful debugging messages when using the OSErr(),
OSWarn() and OSMsg() reporting functions.

**                                                         **
****                                                     ****
************************************************************/
#if OSLOG_MESSAGES > OSLOG_NONE

char *OSMakeStr(char * fmt, ...)
{
    va_list ap;
    
    va_start(ap, fmt);
    vsprintf(OSlogMsg, fmt, ap);
    va_end(ap);
    
    return OSlogMsg;
}

#endif


/************************************************************ 
****                                                     ****
**                                                         **
OSLogErr(fnName, msg)

Debugging function to report and track errors.

**                                                         **
****                                                     ****
************************************************************/
#if OSLOG_MESSAGES >= OSLOG_ERRORS

void OSLogErr( char * name, 
               char * msg  )
{
    OSIncCallDepth();
    
    OSIncErrs();
    
    printf(">%s: ERROR - %s\n", name, msg);
     
    OSDecCallDepth();
}

#endif


/************************************************************ 
****                                                     ****
**                                                         **
OSLogWarn(fnName, msg)

Debugging function to report and track warnings.

**                                                         **
****                                                     ****
************************************************************/
#if OSLOG_MESSAGES >= OSLOG_WARNINGS

void OSLogWarn( char * name, 
                char * msg  )
{
    OSIncCallDepth();
    
    OSIncWarns();
    
    printf(">%s: WARNING - %s\n", name, msg);
     
    OSDecCallDepth();
}

#endif


/************************************************************ 
****                                                     ****
**                                                         **
OSLogMsg(fnName, msg)

Debugging function to report simple messages.

**                                                         **
****                                                     ****
************************************************************/
#if OSLOG_MESSAGES >= OSLOG_ALL

void OSLogMsg( char * name, 
               char * msg  )
{
    OSIncCallDepth();
    
    printf(">%s: %s\n", name, msg);
    
    OSDecCallDepth();
}

#endif
