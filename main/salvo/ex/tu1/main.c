/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu1\\main.c,v $
$Author: aek $
$Revision: 3.4 $
$Date: 2003-01-09 14:03:03-08 $

Source for tutorial programs.

************************************************************/

#include "main.h"
#include "salvo.h"

void main( void )
{
    Init();

    OSInit();
	
    for (;;)
    {
        OSSched();
    }
}

