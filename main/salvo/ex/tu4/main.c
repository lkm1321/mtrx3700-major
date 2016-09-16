/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu4\\main.c,v $
$Author: aek $
$Revision: 3.10 $
$Date: 2003-06-13 17:05:13-07 $

Source for tutorial programs.

************************************************************/

#include "main.h"
#include "salvo.h"

#define TASK_COUNT_P      OSTCBP(1) /* task #1        */
#define TASK_SHOW_P       OSTCBP(2) /* task #2        */
#define PRIO_COUNT        10        /* task priorities*/
#define PRIO_SHOW         10        /*  ""            */
#define BINSEM_UPDATE_PORT_P OSECBP(1) /* binSsem #1  */

_OSLabel(TaskCount1)
_OSLabel(TaskShow1)

unsigned int counter;

void TaskCount( void )
{
    for (;;) {
        counter++;
        
        if ( !(counter & 0x01FF) )
            OSSignalBinSem(BINSEM_UPDATE_PORT_P);
    
        OS_Yield(TaskCount1);
    }
}

void TaskShow( void )
{
    InitPORT();
    
    for (;;) {
        OS_WaitBinSem(BINSEM_UPDATE_PORT_P, OSNO_TIMEOUT, TaskShow1);
        
        PORT = (PORT & ~0xFE) | ((counter >> 8) & 0xFE);
    }
}

void main( void )
{
    Init();

    OSInit();
    
    OSCreateTask(TaskCount, TASK_COUNT_P, PRIO_COUNT);
    OSCreateTask(TaskShow,  TASK_SHOW_P,  PRIO_SHOW);
    
    OSCreateBinSem(BINSEM_UPDATE_PORT_P, 0);
    
    counter = 0;

    for (;;)
        OSSched();
}

