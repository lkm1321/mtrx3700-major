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

$Source: C:\\RCS\\d\\salvo\\src\\delay.c,v $
$Author: aek $
$Revision: 3.9 $
$Date: 2003-07-24 15:18:20-07 $

OSDelay() -- delay a task.

************************************************************/

#include <salvo.h>

#if OSENABLE_DELAYS


/************************************************************ 
****                                                     ****
**                                                         **
OSDelay(delay, delayIsInterval)

Delay the current task by the specified number of system
ticks. If the delay specified is an interval, the delay 
is calculated relative to the timestamp that was taken when
the task last timed out.

Internal processing varies based on whether ticks are 
enabled -- if so, OSDelay() has to detect whether we want
a simple delay or a synchronized delay.

Note: Context switch immediately after OSDelay()!

Note: If the specified delay is 0, the task is stopped.

Note: If delays are enabled, OS_Stop() is implemented 
through OSDelay(0) to save some code space and avoid any
problems with the user specifying OSDelay(0). If delays
are not enabled, OSStop() is called directly.

**                                                         **
****                                                     ****
************************************************************/
#define __OSDELAY_DELAY_C
#include <salvomcg.h>

#if !OSENABLE_TICKS
OSMONITOR_KEYWORD_PRE
void OSDelay( OStypeDelay   delay )
OSMONITOR_KEYWORD_POST
#else
OSMONITOR_KEYWORD_PRE
void OSDelay( OStypeDelay   delay,
              OStypeBoolean useTS )
OSMONITOR_KEYWORD_POST
#endif             
{    
    #if OSENABLE_TICKS    
    OStypeDelay    diff;
    #endif
    
    OSBeginCriticalSection();
    OSIncCallDepth();    
        
    /* if delay is specified as zero, it means that we    */
    /*  want to stop the current task.                    */
    if ( delay == 0 ) {
        /* make the task STOPPED. */
        OScTcbP->status.bits.state = OSTCB_TASK_STOPPED;
        
        /* and tell about it.                             */
        OSDecCallDepth();    
        OSEndCriticalSection();
        OSMsg("OSDelay", OSMakeStr("task %d stopped.",
          OStID(OScTcbP)));
    }
    
    /* a non-zero delay means we want a real delay. */
    else {
        /* make the task DELAYED. */
        OScTcbP->status.bits.state = OSTCB_TASK_DELAYED;

        #if !OSENABLE_TICKS    
        /* set the delay field. */
        OScTcbP->dly.delay = delay;
        
        #else
        if ( !useTS )
            /* placeholder (see below). */
            diff = delay;
            
        else {
            /* set the delay field based on the     */
            /*  desired interval and how much time  */
            /*  has elapsed since the task last     */
            /*  timed out. Do it in three separate  */
            /*  steps to avoid type conversion      */
            /*  warnings with this unsigned math.   */
            diff  =                      delay; 
            diff +=     OScTcbP->dly.timestamp;
            diff -= (OStypeDelay) OStimerTicks;
              
            /* if we arrived too late on the scene, */
            /*  "add an extra interval" so that     */
            /*  we're back on track for next time.  */
            if ( diff > delay ) {
                diff += delay;
                OSWarn("OSDelay",
                  OSMakeStr("task %d overshot specified interval at %d system ticks",
                    OStID(OScTcbP), OStimerTicks));
            }
    
            /* and set the desired delay prior to   */
            /* delaying    the task.                */              
        }
        
        /* finally, set the delay field.            */
        OScTcbP->dly.delay = diff;
        #endif
        
        
        /* put it into the delay queue. */
        #if !OSENABLE_TIMEOUTS && !OSUSE_ARRAYS
        OSInsPrio(OScTcbP, &OSdelayQP);
        #else
        OSInsDelay(OScTcbP);
        #endif

        /* and tell about it.                        */
        OSDecCallDepth();    
        OSEndCriticalSection();
        OSMsg("OSDelay", OSMakeStr("task %d delayed for %u ticks.",
          OStID(OScTcbP), OScTcbP->dly.delay));
    }
}

#include <salvoscg.h>
#undef __OSDELAY_DELAY_C

#endif /*  #if OSENABLE_DELAYS */

