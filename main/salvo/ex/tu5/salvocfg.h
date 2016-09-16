/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.

$Source: C:\\RCS\\d\\salvo\\tut\\tu5\\syse\\salvocfg.h,v $
$Author: aek $
$Revision: 3.6 $
$Date: 2003-07-30 17:31:29-07 $

Header file for tutorial programs.

************************************************************/

#if   defined(MAKE_WITH_FREE_LIB)
/*                                                          */
/*  Salvo Lite build - link with sfc18sfa.lib               */
/*                                                          */
#define OSUSE_LIBRARY               TRUE
#define OSLIBRARY_TYPE              OSF
#define OSLIBRARY_GLOBALS           OSF
#define OSLIBRARY_CONFIG            OSA
#define OSEVENTS                    1
#define OSEVENT_FLAGS               0
#define OSMESSAGE_QUEUES            0
#define OSTASKS                     3


#elif defined(MAKE_WITH_STD_LIB)
/*                                                          */
/*  Salvo LE & Pro library build - link with slc18sfa.lib   */
/*                                                          */
#define OSUSE_LIBRARY               TRUE
#define OSLIBRARY_TYPE              OSL
#define OSLIBRARY_GLOBALS           OSF
#define OSLIBRARY_CONFIG            OSA
#define OSEVENTS                    1
#define OSEVENT_FLAGS               0
#define OSMESSAGE_QUEUES            0
#define OSTASKS                     3


#elif defined(MAKE_WITH_SOURCE) 
/*                                                          */
/*  Salvo Pro source-code build                             */
/*                                                          */
#define OSBYTES_OF_DELAYS           1
#define OSENABLE_BINARY_SEMAPHORES  TRUE
#define OSEVENTS                    1
#define OSTASKS	                    3


#else

#error No MAKE_WITH_??? symbol defined. See salvocfg.h.

#endif

#if !defined(SYSE)

#error SYSE must be defined for this MPLAB-C18 tutorial project ...

#endif
