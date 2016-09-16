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

The Original Code is Salvo - the Cooperative, Multitasking
RTOS. Copyright (C) 1995-2001 Pumpkin, Inc. and its
Licensor(s). All Rights Reserved.

$Source: C:\\RCS\\d\\salvo\\inc\\user\\portuser.h,v $
$Author: aek $
$Revision: 3.0 $
$Date: 2002-01-19 10:12:17-08 $

User-defineable porting file.

************************************************************/

/* include necessary header files here -- uncomment or add */
/*  as needed. */
/* #include <stdio.h> */
/* #include <string.h> */
/* #include <stdarg.h> */


/* define your environment's disabling of interrupts here. */
#ifndef OSDi
#define OSDi()
#endif


/* define your environment's enabling of interrupts here.     */
#ifndef OSEi
#define OSEi()
#endif


/* choose your context-switching methodology here.             */
#define OSCTXSW_METHOD OSRTNADDR_IS_PARAM


/* set OSrtnAddr offset here, if applicable.                 */
#define OSRTNADDR_OFFSET 0


/* if your compiler doesn't pass parameters on the stack,    */
/*  then use these definitions. O/wise clear them.            */
#define OSProtect()   OSEnterCritical()
#define OSUnprotect() OSLeaveCritical()


/* define how a task returns to the scheduler here. This is    */
/*  usually just a "return-from-subroutine" assembly-level    */
/*  instruction for non-stack-based targets. Some stack     */
/*  cleanup    may also be required.                            */
#define OSRtnToOSSched()
 
 
/* define your Salvo-compatible context-switcher here.         */
#define OS_Yield(label)


/* define your context-switching label declarator here.        */
#define _OSLabel(a)


/* use this if RAM banking directives are necessary.        */
#define OSLOC_DEFAULT


/* set this to FALSE if memset() can't handle banked memory    */
#define OSUSE_MEMSET     TRUE


/* you'll need to change this if you're doing advanced       */
/*  things with tasks or context switches.                    */
#define OSTASK_POINTER_TYPE


/* redefine this if void pointers don't    span your target    */
/*  processor's entire address space.                        */
#define OSMESSAGE_TYPE void


/* If your compiler allows you to pack bit fields in        */
/*  structures into char-sized objects (instead of ANSI's    */
/*  int-sized objects specification), set this to TRUE.        */
#define OSUSE_CHAR_SIZED_BITFIELDS    FALSE






