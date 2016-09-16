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

$Source: C:\\RCS\\d\\salvo\\src\\idle.c,v $
$Author: aek $
$Revision: 3.3 $
$Date: 2003-07-24 15:18:28-07 $

The user-defined idling hook. Executed whenever the 
scheduler is idling, i.e. there are no eligible tasks to
run.

NOTE: Users SHOULD NOT modify this file. Rather, users
should define their own OSIdlingHook() and use it instead.
This file exists mainly to ensure that Salvo libraries 
contain a default OSIdlingHook() so that users need only
define an OSIdlingHook() if they need one that actually
does something ...

************************************************************/

#include <salvo.h>

void OSIdlingHook( void )
{
    ;
}
