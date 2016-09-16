/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu2\\main.c,v $
$Author: aek $
$Revision: 3.6 $
$Date: 2003-01-09 14:03:03-08 $

Source for tutorial programs.

************************************************************/

#include "main.h"
#include "salvo.h"

_OSLabel(TaskA1)
_OSLabel(TaskB1)


void TaskA( void )
{
    for (;;)
    {
        OS_Yield(TaskA1);
    }
}


void TaskB( void )
{
    for (;;)
    {
        OS_Yield(TaskB1);
    }
}


void main( void )
{
    Init();
    
    OSInit();
    
    OSCreateTask(TaskA, OSTCBP(1), 10);
    OSCreateTask(TaskB, OSTCBP(2), 10);
    
    for (;;)
    {
        OSSched();
    }
}

