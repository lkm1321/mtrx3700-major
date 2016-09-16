/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu3\\main.c,v $
$Author: aek $
$Revision: 3.7 $
$Date: 2003-06-13 17:05:13-07 $

Source for tutorial programs.

************************************************************/

#include "main.h"
#include "salvo.h"

_OSLabel(TaskCount1)
_OSLabel(TaskShow1)

unsigned int counter;


void TaskCount( void )
{
    for (;;)
    {
        counter++;
    
        OS_Yield(TaskCount1);
    }
}


void TaskShow( void )
{
    InitPORT();
    
    for (;;)
    {
        PORT = (PORT & ~0xFE) | ((counter >> 8) & 0xFE);
        
        OS_Yield(TaskShow1);
    }
}


void main( void )
{
    Init();

    OSInit();
    
    OSCreateTask(TaskCount, OSTCBP(1), 10);
    OSCreateTask(TaskShow,  OSTCBP(2), 10);
    
    counter = 0;

    for (;;)
    {
        OSSched();
    }
}


