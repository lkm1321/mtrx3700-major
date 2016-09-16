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

$Source: C:\\RCS\\d\\salvo\\src\\license.c,v $
$Author: aek $
$Revision: 3.6 $
$Date: 2003-07-24 15:18:27-07 $

The purpose of this file is to embed this notice into Salvo
libraries, e.g. the freeware libraries.

************************************************************/
#if !defined(__OSLICENSE_C)
#define __OSLICENSE_C


#include <salvo.h>

#if ( OSCOMPILER != OSKEIL_C51 )
const char OSlicense0[] = \
"The contents of this file are subject to the Pumpkin Salvo" \
"License (the \"License\"). You may not use this file except" \
"in compliance with the License. You may obtain a copy of" \
"the License at http://www.pumpkininc.com, or from" \
"warranty@pumpkininc.com. Reverse Engineering Prohibited. ";

const char OSLicense1[] = \
"Software distributed under the License is distributed on an" \
"\"AS IS\" basis, WITHOUT WARRANTY OF ANY KIND, either express" \
"or implied. See the License for specific language governing" \
"the warranty and the rights and limitations under the" \
"License. ";

const char OSLicense2[] = \
"The Original Code is Salvo - The RTOS that runs in tiny" \
"places(TM). Copyright (C) 1995-2002 Pumpkin, Inc. and its" \
"Licensor(s). All Rights Reserved.";
#endif /* #if ( OSCOMPILER != OSKEIL_C51 ) */

#endif /* include guard */

