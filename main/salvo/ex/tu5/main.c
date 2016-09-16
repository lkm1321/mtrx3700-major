/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu5\\main.c,v $
$Author: aek $
$Revision: 3.7 $
$Date: 2003-06-13 17:05:12-07 $

Source for tutorial programs.

************************************************************/

#include "main.h"
#include "salvo.h"

#define TASK_COUNT_P      OSTCBP(1) /* task #1        */
#define TASK_SHOW_P       OSTCBP(2) /*  ""  #2        */
#define TASK_BLINK_P      OSTCBP(3) /*  ""  #3        */
#define PRIO_COUNT        10        /* task priorities*/
#define PRIO_SHOW         10        /*  ""            */
#define PRIO_BLINK        2         /*  ""            */
#define BINSEM_UPDATE_PORT_P OSECBP(1) /* binSem #1   */

unsigned int counter;

_OSLabel(TaskCount1)
_OSLabel(TaskShow1)
_OSLabel(TaskBlink1)


void TaskCount( void )
{
    for (;;)
    {
        counter++;
        
        if ( !(counter & 0x01FF) )
        {
            OSSignalBinSem(BINSEM_UPDATE_PORT_P);
        }
    
        OS_Yield(TaskCount1);
    }
}


void TaskShow( void )
{
    for (;;)
    {
        OS_WaitBinSem(BINSEM_UPDATE_PORT_P, OSNO_TIMEOUT, TaskShow1);
        
        PORT = (PORT & ~0xFE) | ((counter >> 8) & 0xFE); 
    }
}


void TaskBlink( void )
{
    InitPORT();
    
    for (;;) 
    {
        PORT ^= 0x01;
        
        OS_Delay(50, TaskBlink1);
    }
}


void main( void )
{
    Init();
    
    OSInit();
    
    OSCreateTask(TaskCount, TASK_COUNT_P, PRIO_COUNT);
    OSCreateTask(TaskShow,  TASK_SHOW_P,  PRIO_SHOW);
    OSCreateTask(TaskBlink, TASK_BLINK_P, PRIO_BLINK);
    
    OSCreateBinSem(BINSEM_UPDATE_PORT_P, 0);
    
    counter = 0;

    OSEi(); 
    
    for (;;)
    {
        OSSched();
    }
}

#pragma code .idata_license = 0x8000