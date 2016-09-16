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

$Source: C:\\RCS\\d\\salvo\\src\\delay2.c,v $
$Author: aek $
$Revision: 3.10 $
$Date: 2003-07-24 15:18:20-07 $

OSSyncTS() -- synchronize current task's timestamp against 
current system ticks counter.

************************************************************/

#include <salvo.h>

#if OSENABLE_DELAYS && OSENABLE_TICKS


/************************************************************ 
****                                                     ****
**                                                         **
OSSyncTSTask(tcbP, interval)

This function allows us to set the task's timestamp relative
to the current system tick.

Note: Written for portability due to the signed-vs-unsigned 
math here ...

Also, using the more direct form consumes three fewer
instructions on a PIC (and needs no local variable), but is
saddled with the "conversion to shorter data type" warning.

**                                                         **
****                                                     ****
************************************************************/
#define __OSSYNCTSTASK_DELAY2_C
#include <salvomcg.h>

OSMONITOR_KEYWORD_PRE
void OSSyncTSTask( OStypeTcbP     tcbP,
                   OStypeInterval interval )
OSMONITOR_KEYWORD_POST
{    
    OStypeTS timestamp;

    OSBeginCriticalSection();
    OSIncCallDepth();    

    /* first, get timestamp for right now. OStimerTicks  */
    /*  is truncated to sizeof(OStypeTS). Both are       */
    /*  unsigned, so it's not an issue.                  */
#if 1
    timestamp = (OStypeTS) OStimerTicks;
    
    /* then adjust it based on the interval. Treating    */
    /*  interval as unsigned works fine here because of  */
    /*  sizeof(OStypeTS). If interval is negative,       */
    /*  making it unsigned and adding it is just like    */
    /*  subtracting it in the first place.               */
    timestamp += (OStypeTS) interval;
    
    /* finally, write the task's timestamp.              */
    OSSetTSTask(tcbP, timestamp);
#else
    OSSetTSTask(tcbP, (OStypeTS)((OStypeTS) OStimerTicks + (OStypeTS) interval));
#endif
    /* finish up. */
    OSDecCallDepth();    
    OSEndCriticalSection();
    OSMsg("OSSyncTS", OSMakeStr("task %d's timestamp field set to %d",
      OStID(OScTcbP), OScTcbP->dly.delay));
}

#include <salvoscg.h>
#undef __OSSYNCTSTASK_DELAY2_C

#endif /*  #if OSENABLE_DELAYS && OSENABLE_TICKS */

