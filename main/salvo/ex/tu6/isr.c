/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.
`
$Source: C:\\RCS\\d\\salvo\\tut\\tu1\\isr.c,v $
$Author: aek $
$Revision: 3.22 $
$Date: 2003-07-28 18:41:36-07 $

Source for tutorial programs. Contains the interrupt service
routine and other interrupt-associated code for all of
the tutorials. Organized by compiler and target (SYS*).

************************************************************/

#include "isr.h"
#include <salvo.h>

#if   defined(USE_INTERRUPTS)

#if defined(SYSE)

#pragma interrupt 

void ISRHigh( void )
{
    if ( INTCONbits.TMR0IE && INTCONbits.TMR0IF )
    {
        INTCONbits.TMR0IF = 0;
        TMR0 -= TMR0_RELOAD;

        OSTimer();
    }
}

#pragma code IntVectorHigh = 0x08
void IntVectorHigh( void )
{ 	
    _asm
    goto	ISRHigh
    _endasm
}



#else /* SYS* not defined */

#error Undefined Salvo test system (SYS*). Definition required.

#endif

#endif

