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

$Source: C:\\RCS\\d\\salvo\\src\\portpic18.c,v $
$Author: aek $
$Revision: 3.16 $
$Date: 2003-07-24 15:18:26-07 $

Code for the Microchip MPLAB-C18 and IAR PIC18 C Compilers.

************************************************************/

#include <salvo.h>

#if ( ( OSTARGET == OSPIC18 ) \
 && ( ( OSCOMPILER == OSIAR_ICC ) || ( OSCOMPILER == OSMPLAB_C18 ) ) )
 

/************************************************************ 
****                                                     ****
**                                                         **
OSCtxSw() for MPLAB-C18 and IAR PIC18 C

Somewhat complicated, in that TOS is not natively of type
OStypeTFP, and varies as a function of the memory model. 

By appropriate casting and dereferencing, we can avoid all
memory-model issues and we can avoid padding the tcb's tFP
field with unused bits (e.g. when the small model is used,
with its 16 bits). IOW, the compiler will handle whether
16 or 24 bits of address are copied from TOS to the tcb's
tFP.

Note: Preserving of interrupt mask is irrelevant, since
it's handled in a software stack separate from the PIC18
hardware stack.

Note: MPLAB-C18's v2.20's procedural abstractions 
optimizations are incompatible with OSCtxSw() because pa
introduces an extra RCALL on top of the existing CALL.
Therefore any task with two or more Salvo context switches
must have -Opa- applied to its source module to avoid this.
                 
**                                                         **
****                                                     ****
************************************************************/
void OSCtxSw( void )
{
	
    OSBeginCriticalSection();
    OSIncCallDepth();
       
	OScTcbP->tFP = * ((OStypeTFP *) &TOSL);
     
    STKPTR--;
    	
    OSDecCallDepth();
    OSEndCriticalSection();    
}


/************************************************************ 
****                                                     ****
**                                                         **
OSSave|RestoreInstat() for PIC18

To be compatible with high/low interrupt priority scheme,
we must manage both GIE/GIEH and PEIE/GIEL bits. This 
"synthesized stack" allows us to restore interrupt status
upon exit from Salvo functions that have critical sections.

Normally, this is coded in C (as opposed to faster assembly) 
to ensure the banking is done right. Also, it's placed in a 
function (as opposed to in-lined) because it's so large / 
slow.

Can save interrupt status 8 levels deep in each case.

NOTE: Lack of *=2 and /=2 optimizations in IAR compiler   
        force us to use in-line assembly. Rotate-by-1-with-
        carry is equivalent to shift-by-one. Also, for
        IAR PIC18 implementation, OSsavePIC18GIE|PEIE must 
        be __nonbanked!  
                    
**                                                         **
****                                                     ****
************************************************************/
#if   ( OSCOMPILER == OSIAR_ICC )
void OSSaveIntStat( void )
{
	/* make room for new int bit, save int bit and      */
	/*  disable ints by clearing int bit. Do periphs /  */
	/*  low-levels first since mains / high-levels have */
	/*  priority.                                       */
	
	/* do peripheral/low-level (PEIE/GIEL) ints.        */
	#if   ( OSPIC18_INTERRUPT_MASK & 0x40 )
	
	STATUS &= ~0x01;                /* clear carry flag */
	asm("RLCF OSsavePIC18PEIE,1,0");
    if ( PEIE ) OSsavePIC18PEIE |= 0x01;
    PEIE = 0;
    
	#endif
	
	
	/* do global/high-level (GIE/GIEH) ints.            */
	#if   ( OSPIC18_INTERRUPT_MASK & 0x80 )
	
	STATUS &= ~0x01; 
	asm("RLCF OSsavePIC18GIE,1,0");
    if ( GIE ) OSsavePIC18GIE |= 0x01;
    GIE  = 0;
    
    #endif
}

void OSRestoreIntStat( void )
{
	/* restore int bit from saved copy, "pop" saved     */
	/*  copy.                                           */
	
	/* do global/high-level (GIE/GIEH) ints.            */
	#if   ( OSPIC18_INTERRUPT_MASK & 0x80 )
	
	if ( OSsavePIC18GIE & 0x01 ) GIE  = 1;
	STATUS &= ~0x01; 
	asm("RRCF OSsavePIC18GIE,1,0");
	
	#endif


	/* do peripheral/low-level (PEIE/GIEL) ints.        */
	#if   ( OSPIC18_INTERRUPT_MASK & 0x40 )
	
	if ( OSsavePIC18PEIE & 0x01 ) PEIE = 1;
	STATUS &= ~0x01; 
	asm("RRCF OSsavePIC18PEIE,1,0");
	
	#endif
}

#endif
	
#endif /* #if */
