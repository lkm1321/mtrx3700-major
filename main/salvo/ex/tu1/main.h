/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu1\\main.h,v $
$Author: aek $
$Revision: 3.33 $
$Date: 2003-10-20 18:05:14-07 $

Header file for tutorial programs.

************************************************************/
                                                            
/*                                                          */                                                                
/* ===================== PICmicro ========================= */
/*                                                          */                                                                
#if   defined(SYSE) /* Microchip MPLAB-C18  */

/* setup which port to use, and initialize it */
#define PORT                PORTB
#define InitPORT()          do { \
                                PORTB = 0x00; \
                                TRISB = 0x00; \
                            } while (0)

/* when interrupts are used (tu5 & tu6), they need to be    */
/*  appropriately initialized.                              */
#if !defined(USE_INTERRUPTS)

#define Init()

#else

/*  MPLAB-C18 uses different nomenclature for certain PIC18 */
/*   family members                                         */    
#if  defined(__18C601)  || defined(__18C658)  || defined(__18C801)  \
 ||  defined(__18C858)  || defined(__18F2220) || defined(__18F2320) \
 ||  defined(__18F2331) || defined(__18F2431) || defined(__18F4220) \
 ||  defined(__18F4320) || defined(__18F4331) || defined(__18F4431)
#define Init()              do { \
                                T0CONbits.T0CS    = 0; \
                                T0CONbits.T0PS0   = 1; \
                                T0CONbits.T0PS1   = 0; \
                                T0CONbits.T0PS2   = 1; \
                                T0CONbits.T0PS3   = 0; \
                                INTCONbits.TMR0IE = 1; \
                            } while (0)
#else
#define Init()              do { \
                                T0CONbits.T0CS    = 0; \
                                T0CONbits.T0PS0   = 1; \
                                T0CONbits.T0PS1   = 0; \
                                T0CONbits.T0PS2   = 1; \
                                T0CONbits.PSA     = 0; \
                                INTCONbits.TMR0IE = 1; \
                            } while (0)
#endif                          
                          
#endif                               

/*                                                          */                                                                
/* ====================== undefined ======================= */
/*                                                          */                                                                
#else

#error Undefined Salvo test system (SYS*). Definition required.

#endif
