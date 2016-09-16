/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu6\\main.c,v $
$Author: aek $
$Revision: 3.10 $
$Date: 2003-07-08 23:15:13-07 $

Source for tutorial programs.

************************************************************/

#include "main.h"
#include "salvo.h"

#define TASK_COUNT_P      OSTCBP(1) /* task #1        */
#define TASK_SHOW_P       OSTCBP(2) /*  ""  #2        */
#define TASK_BLINK_P      OSTCBP(3) /*  ""  #3        */
#define PRIO_COUNT        12        /* task priorities*/
#define PRIO_SHOW         10        /*  ""            */
#define PRIO_BLINK        2         /*  ""            */
#define MSG_UPDATE_PORT_P OSECBP(1) /* semaphore #1   */


unsigned int counter;

char CODE_B = 'B';
char CODE_C = 'C';

_OSLabel(TaskCount1)
_OSLabel(TaskShow1)
_OSLabel(TaskBlink1)
_OSLabel(TaskBlink2)


void TaskCount( void )
{
    counter = 0;

    for (;;)
    {
        counter++;
        
        if ( !(counter & 0x01FF) )
        {
        	OSSignalMsg(MSG_UPDATE_PORT_P, (OStypeMsgP) &CODE_C);
        }
    
        OS_Yield(TaskCount1);
    }
}


void TaskShow( void )
{
    OStypeMsgP msgP;
       
    InitPORT();
    
    for (;;)
    {
        OS_WaitMsg(MSG_UPDATE_PORT_P, &msgP, OSNO_TIMEOUT, TaskShow1);
        
        if ( *(char *)msgP == CODE_C )
        {
            PORT = (PORT & ~0xFE) | ((counter >> 8) & 0xFE);
        }
        else
        {
            PORT ^= 0x01;
        }
    }
}


void TaskBlink( void )
{
    OStypeErr err;
	
	
    for (;;)
    {
        OS_Delay(50, TaskBlink1);

        err = OSSignalMsg(MSG_UPDATE_PORT_P, (OStypeMsgP) &CODE_B);
        
        if ( err == OSERR_EVENT_FULL )
        {
        	OS_SetPrio(PRIO_SHOW+1, TaskBlink2);
        	OSSignalMsg(MSG_UPDATE_PORT_P, (OStypeMsgP) &CODE_B);
        	OSSetPrio(PRIO_BLINK);
        }      
    }
}


void main( void )
{
    Init();
    
    OSInit();
    
    OSCreateTask(TaskCount, TASK_COUNT_P, PRIO_COUNT);
    OSCreateTask(TaskShow,  TASK_SHOW_P,  PRIO_SHOW);
    OSCreateTask(TaskBlink, TASK_BLINK_P, PRIO_BLINK);
    
    OSCreateMsg(MSG_UPDATE_PORT_P, (OStypeMsgP) 0); 
    
    OSEi(); 
    
    for (;;)
    {
        OSSched();
    }
}
