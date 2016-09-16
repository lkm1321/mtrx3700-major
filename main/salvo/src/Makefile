###########################################################################################
# The contents of this file are subject to the Pumpkin Salvo
# License (the "License").  You may not use this file except
# in compliance with the License. You may obtain a copy of
# the License at http://www.pumpkininc.com, or from
# warranty@pumpkininc.com.
# 
# Software distributed under the License is distributed on an
# "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express
# or implied. See the License for specific language governing
# the warranty and the rights and limitations under the
# License.
# 
# The Original Code is Salvo - the Cooperative, Multitasking
# RTOS. Copyright (C) 1995-2001 Pumpkin, Inc. and its
# Licensor(s). All Rights Reserved.
# 
# $Source: C:\\RCS\\d\\salvo\\src\\Makefile,v $
# $Author: aek $
# $Revision: 3.33 $
# $Date: 2003-07-20 13:06:50-07 $
# 
#   Makefile for Salvo freeware and standard libraries for 
# compilers with command-line interfaces.
# 
#   Runs under Cygwin's bash shell, and presumably others, too. Created and tested
# under GNU make 3.79.1.
# 


###########################################################################################
#
#   The approach here to parsing the target name (a library name) and then recursively
# calling make with a bunch of passed variables based on the library name was proposed
# by Jonathan Kamens (jik@kamens.brookline.ma.us) in response to aek's query in the
# gnu.utils.help newgroup on 2001-08-31.
#
#   The idea is to use a Unix/Linux shell and regular expression to extract the chars
# of interest from a string, and then return a key based on those chars.
#

# $(1) is target, $(2) is regexp to retrieve index chars
INDEX=$(shell expr '$(1)' : '$(2)')


# $(1) is index chars, $(2) is list of key/value pairs
PAIR=$(filter $(1)@%,$(2))


# $(1) is index chars, $(2) is individual key/value pair
VAL=$(patsubst $(1)@%,%,$(2))


# $(1) is target, $(2) is regexp to retrieve index chars, $(3) is list
# of key/value pairs
GETVAL = $(call VAL,$(call INDEX,$(1),$(2)),$(call PAIR,$(call INDEX,$(1),$(2)),$(3)))


###########################################################################################
#
# Defaults if user hasn't specified them on the command line.
#
# CLC is for custom library configurations -- CLC=0 means no custom library config.
#
# CVER is for compiler version -- CVER=1 means "compiler version v1.x"
#
ifndef ($(CLC))
  CLC = 0
endif

ifndef ($(CVER))
  CVER = 1
endif


###########################################################################################
#
#   T means library type.
#   T = f means freeware library
#   T = l means standard library
#
TYPE_VALS    = sf@OSF sl@OSL


###########################################################################################
#
#   F means family (a combination of compiler used AND target processor).
#   See Makefile2 for more information.
#
FAMILY_VALS  = p200@p200 p210@p210 p211@p211 p212@p212 p222@p222 \
               p400@p400 p401@p401 p402@p402 p40a@p40a p40b@p40b \
               p40c@p40c p411@p411 p412@p412 p41b@p41b p41c@p41c \
               p422@p422 p42c@p42c p432@p432 p43c@p43c p926@p926 \
               p700@p700 p704@p704 p710@p710 p714@p714 \
               p80s@p80s p80l@p80l p81s@p81s p81l@p81l \
               p82s@p82s p82l@p82l p83s@p83s p83l@p83l \
               p86s@p86s p86l@p86l p87s@p87s p87l@p87l \
               c18@c18 \
               iar18@iar18 \
               cv8@cv8 \
               gccx86@gccx86 gcc6811@gcc6811 \
               aq430@aq430 \
               cs430@cs430 \
               iar430@iar430 \
               icc430@icc430 \
               icc11@icc11 \
               c51@c51 cx51@cx51 51@51 \
               ez8@ez8 \
               tic28x@tic28x tic24x@tic24x \
               iccavr@iccavr iccatmega@iccatmega \
               gccavr@gccavr
              
              
###########################################################################################
#
#   M means memory model.
#   M = s means small memory model (the default)
#   M = c means compact memory model
#   M = m means medium memory model
#   M = l means large memory model
#
MODEL_VALS = c@OSC C@OSC l@OSL L@OSL m@OSM M@OSM s@OSS S@OSS


###########################################################################################
#
#   O means library option
#   - = no option
#   I = library includes embedded source-level debug information
#
OPTION_VALS = i@OSI I@OSI -@OSNONE


###########################################################################################
#
#   G means memory type (for Salvo global objects).
#   G = - means the default memory type
#   G = d means data memory type
#   G = f means far memory type
#   G = i means idata memory type
#   G = n means near memory type
#   G = x means xdata memory type
#
GLOBAL_VALS = d@OSD D@OSD f@OSF F@OSF i@OSI I@OSI n@OSN N@OSN x@OSX X@OSX -@OSNONE


###########################################################################################
#
#   C means library configuration.
#   C = a means library supports multitasking, delays and events
#   C = d means library supports delays only
#   C = e means library supports events only
#   C = m means library supports multitasking only
#   C = t means library supports multitasking, delays and events with timeouts
#   C = s for SE libraries only
#   C = y for tiny libraries only
#
CONFIG_VALS  = a@OSA A@OSA d@OSD D@OSD e@OSE E@OSE m@OSM M@OSM s@OSS S@OSS t@OST T@OST y@OSY Y@OSY


###########################################################################################
#
#   V means library variant.
#   V = - means no variant
#   V = a means services can be called from anywhere , simultaneously 
#   V = b means services can only be called from the background only
#   V = e means services can only be called from either the background or the foreground, but not both
#   V = i means that debugging information is included in the library
#   V = f means services can only be called from the background only
#
VARIANT_VALS = a@OSA A@OSA b@OSB B@OSB e@OSE E@OSE f@OSF F@OSF -@OSNONE


###########################################################################################
#
#   include target variables
#
include targets.mk


###########################################################################################
#
#   help targets: (default rule)
#
liblist listlib help :
	@echo "  Salvo make utility."
	@echo "  In addition to individual libraries (e.g. sfp42cab.lib), the following"
	@echo "targets can be specified by family. For each one (e.g. p4xx), all types,"
	@echo "configurations and variants will be built. The appropriate compiler must" 
	@echo "be installed for each family."
	@echo " all" 
	@echo "  8051"
	@echo "   $(HT_C51_FAMILIES)"
	@echo "   $(KEIL_C51_FAMILIES)"
	@echo "   $(KEIL_Cx51_FAMILIES)"
	@echo "  avr"
	@echo "   $(GCC_AVR_FAMILIES)"
	@echo "   $(ICC_AVR_FAMILIES)"
	@echo "   $(ICC_ATMEGA_FAMILIES)"
	@echo "  $(HT_V8C_cv8_FAMILIES)"
	@echo "  $(ZLG_EZ8_FAMILIES)"
	@echo "  $(GCC_6811_FAMILIES)"
	@echo "  $(GCC_x86_FAMILIES)"
	@echo "  m68hcxx"
	@echo "   $(ICC_11_FAMILIES)"
	@echo "  msp430"
	@echo "   $(AQ_430_FAMILIES)"
	@echo "   $(CS_430_FAMILIES)"
	@echo "   $(IAR_430_V1_FAMILIES)"
	@echo "   $(IAR_430_V2_FAMILIES)"
	@echo "   $(ICC_430_FAMILIES)"
	@echo "  pic"
	@echo "   $(MPLAB_C18_FAMILIES)"
	@echo "   $(IAR_PIC18_FAMILIES)"
	@echo "   p2xx"
	@echo "    $(HT_PICC_p2xx_FAMILIES)" 
	@echo "   p4xx"
	@echo "    $(HT_PICC_p4xx_FAMILIES)"
	@echo "   p7xx"
	@echo "    $(HT_PICC_p7xx_FAMILIES)" 
	@echo "   p8xx"
	@echo "    $(HT_PICC_p8xx_FAMILIES)"
	@echo "  tms320c2000"
	@echo "    $(TI_C2400_FAMILIES)"
	@echo "    $(TI_C2800_FAMILIES)"


###########################################################################################
#
#   housekeeping targets:
#
rmobjs :	
	@rm -f *.obj *.OBJ *.o *.O *.r43

rmlsts :	
	@rm -f *.lst *.LST

rmsdbs :	
	@rm -f *.sdb *.SDB

rmrlfs :	
	@rm -f *.rlf *.RLF


###########################################################################################
#
#   maintenance targets:
#
clean:	rmobjs rmlsts rmsdbs rmrlfs

clobber: clean
	@cd ../lib/gcc6811		; rm -f $(GCC_6811_LIBRARIES)
	@cd ../lib/gccx86		; rm -f $(GCC_x86_LIBRARIES)
	@cd ../lib/gccavr 		; rm -f $(GCC_AVR_LIBRARIES)
	@cd ../lib/iccavr 		; rm -f $(ICC_AVR_LIBRARIES)
	@cd ../lib/iccavr		; rm -f $(ICC_ATMEGA_LIBRARIES)
	@cd ../lib/cv8     		; rm -f $(HT_V8C_cv8_LIBRARIES)
	@cd ../lib/picc   		; rm -f $(HT_PICC_p2xx_LIBRARIES)
	@cd ../lib/picc 		; rm -f $(HT_PICC_p4xx_LIBRARIES)
	@cd ../lib/picc 		; rm -f $(HT_PICC_p7xx_LIBRARIES)
	@cd ../lib/picc18		; rm -f $(HT_PICC_p8xx_LIBRARIES)
	@cd ../lib/c18 			; rm -f $(MPLAB_C18_LIBRARIES)
	@cd ../lib/iar18		; rm -f $(IAR_PIC18_LIBRARIES)
	@cd ../lib/ht51			; rm -f $(HT_C51_LIBRARIES)
	@cd ../lib/aq430		; rm -f $(AQ_430_LIBRARIES)
	@cd ../lib/cs430		; rm -f $(CS_430_LIBRARIES)
	@cd ../lib/iar430-v1	; rm -f $(IAR_430_LIBRARIES)
	@cd ../lib/iar430-v2	; rm -f $(IAR_430_LIBRARIES)
	@cd ../lib/icc430 		; rm -f $(ICC_430_LIBRARIES)
	@cd ../lib/icc11  		; rm -f $(ICC_11_LIBRARIES)
	@cd ../lib/cx51			; rm -f $(KEIL_C51_LIBRARIES)
	@cd ../lib/cx51			; rm -f $(KEIL_Cx51_LIBRARIES)
	@cd ../lib/z8encore		; rm -f $(ZLG_EZ8_LIBRARIES)
	@cd ../lib/tic2000		; rm -f $(TI_C2400_LIBRARIES)
	@cd ../lib/tic2000		; rm -f $(TI_C2800_LIBRARIES)
	@rm -f lib.err


###########################################################################################
#
#   library targets:
#
all:
	$(MAKE) $(HT_C51_LIBRARIES)
	$(MAKE) $(KEIL_C51_LIBRARIES)
	$(MAKE) $(KEIL_Cx51_LIBRARIES)
	$(MAKE) $(GCC_AVR_LIBRARIES)
	$(MAKE) $(ICC_AVR_LIBRARIES)
	$(MAKE) $(ICC_ATMEGA_LIBRARIES)
	$(MAKE) $(HT_V8C_cv8_LIBRARIES)
	$(MAKE) $(ZLG_EZ8_LIBRARIES)
	$(MAKE) $(GCC_6811_LIBRARIES)
	$(MAKE) $(GCC_x86_LIBRARIES)
	$(MAKE) $(ICC_11_LIBRARIES)
	$(MAKE) $(AQ_430_LIBRARIES)
	$(MAKE) $(CS_430_LIBRARIES)
	$(MAKE) $(IAR_430_LIBRARIES) CVER=1
	$(MAKE) $(IAR_430_LIBRARIES) CVER=2
	$(MAKE) $(ICC_430_LIBRARIES)
	$(MAKE) $(MPLAB_C18_LIBRARIES)
	$(MAKE) $(IAR_PIC18_LIBRARIES)
	$(MAKE) $(HT_PICC_p2xx_LIBRARIES)
	$(MAKE) $(HT_PICC_p4xx_LIBRARIES)
	$(MAKE) $(HT_PICC_p7xx_LIBRARIES)
	$(MAKE) $(HT_PICC_p8xx_LIBRARIES)
	$(MAKE) $(TI_C2400_LIBRARIES)
	$(MAKE) $(TI_C2800_LIBRARIES)
	@echo Makefile: All libraries appear to have been made successfully.
	
avr:
	$(MAKE) $(GCC_AVR_LIBRARIES)	
	$(MAKE) $(ICC_AVR_LIBRARIES)	
	$(MAKE) $(ICC_ATMEGA_LIBRARIES)	
	
m68hcxx:
	$(MAKE) $(ICC_11_LIBRARIES)
	
	
msp430:
	$(MAKE) $(AQ_430_LIBRARIES)	
	$(MAKE) $(CS_430_LIBRARIES)
	$(MAKE) $(IAR_430_LIBRARIES) CVER=1
	$(MAKE) $(IAR_430_LIBRARIES) CVER=2
	$(MAKE) $(ICC_430_LIBRARIES)
	
8051:	
	$(MAKE) $(HT_C51_LIBRARIES)
	$(MAKE) $(KEIL_C51_LIBRARIES)
	$(MAKE) $(KEIL_Cx51_LIBRARIES)
	
pic:	
	$(MAKE) $(MPLAB_C18_LIBRARIES)
	$(MAKE) $(IAR_PIC18_LIBRARIES)
	$(MAKE) $(HT_PICC_p2xx_LIBRARIES)
	$(MAKE) $(HT_PICC_p4xx_LIBRARIES)
	$(MAKE) $(HT_PICC_p7xx_LIBRARIES)
	$(MAKE) $(HT_PICC_p8xx_LIBRARIES)
	
tms320c2000:	
	$(MAKE) $(TI_C2400_LIBRARIES)
	$(MAKE) $(TI_C2800_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSHT_PICC  OSTARGET == OSPIC12 || OSPIC16 || OSPIC17 || OSPIC18
#
p2xx p4xx p7xx p8xx: 
	$(MAKE) $(HT_PICC_$@_FAMILIES)

$(HT_PICC_p2xx_FAMILIES) \
$(HT_PICC_p4xx_FAMILIES) \
$(HT_PICC_p7xx_FAMILIES) \
$(HT_PICC_p8xx_FAMILIES) :
	$(MAKE) $(HT_PICC_$@_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSMPLAB_C18  OSTARGET == OSPIC18
#
$(MPLAB_C18_FAMILIES) :
	$(MAKE) $(MPLAB_C18_$@_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSIAR_ICC OSTARGET == OSPIC18
#
$(IAR_PIC18_FAMILIES) :
	$(MAKE) $(IAR_PIC18_$@_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSHT_V8C  OSTARGET == OSV8
#
$(HT_V8C_cv8_FAMILIES) :
	$(MAKE) $(HT_V8C_$@_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSHT_C51  OSTARGET == OS8051
#
$(HT_C51_FAMILIES) :
	$(MAKE) $(HT_C51_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSGCC  OSTARGET == OSX86
#
$(GCC_x86_FAMILIES) :
	$(MAKE) $(GCC_x86_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSGCC  OSTARGET == OS6811
#
$(GCC_6811_FAMILIES) :
	$(MAKE) $(GCC_6811_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSGCC  OSTARGET == OSAVR
#
$(GCC_AVR_FAMILIES) :
	$(MAKE) $(GCC_AVR_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSAQ_430 OSTARGET == OSMSP430
#
$(AQ_430_FAMILIES) :
	$(MAKE) $(AQ_430_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSRA_CROSSSTUDIO OSTARGET == OSMSP430
#
$(CS_430_FAMILIES) :
	$(MAKE) $(CS_430_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSIMAGECRAFT OSTARGET == OS68HC11
#
$(ICC_11_FAMILIES) :
	$(MAKE) $(ICC_11_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSIMAGECRAFT OSTARGET == OSMSP430
#
$(ICC_430_FAMILIES) :
	$(MAKE) $(ICC_430_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSIMAGECRAFT OSTARGET == OSAVR
#
$(ICC_AVR_FAMILIES) :
	$(MAKE) $(ICC_AVR_LIBRARIES)


$(ICC_ATMEGA_FAMILIES) :
	$(MAKE) $(ICC_ATMEGA_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSIAR_ICC OSTARGET == OSMSP430
#
$(IAR_430_V1_FAMILIES) :
	$(MAKE) $(IAR_430_LIBRARIES) CVER=1

$(IAR_430_V2_FAMILIES) :
	$(MAKE) $(IAR_430_LIBRARIES) CVER=2


###########################################################################################
#
#   OSCOMPILER == OSZDSII OSTARGET == OSEZ8
#
$(ZLG_EZ8_FAMILIES) :
	$(MAKE) $(ZLG_EZ8_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSTI_CCS_DSP OSTARGET == OSTMS320C28X
#
$(TI_C2800_FAMILIES) :
	$(MAKE) $(TI_C2800_LIBRARIES)

$(TI_C2400_FAMILIES) :
	$(MAKE) $(TI_C2400_LIBRARIES)


###########################################################################################
#
#   OSCOMPILER == OSKEIL_C51  OSTARGET == OS8051
#
$(KEIL_C51_FAMILIES) :
	$(MAKE) $(KEIL_C51_LIBRARIES)
	
$(KEIL_Cx51_FAMILIES) :
	$(MAKE) $(KEIL_Cx51_LIBRARIES)


###########################################################################################
#
#   targets: libraries for HI-TECH PICC, PICC-Lite and PICC-18
#
$(HT_PICC_p2xx_LIBRARIES) \
$(HT_PICC_p4xx_LIBRARIES) \
$(HT_PICC_p7xx_LIBRARIES) \
$(HT_PICC_p8xx_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,..\(....\)..\.lib,$(FAMILY_VALS)) \
		C=$(call GETVAL,$@,.*\(.\).\.lib,$(CONFIG_VALS)) \
		V=$(call GETVAL,$@,.*\(.\)\.lib,$(VARIANT_VALS)) \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for MPLAB-C18 and PIC18 targets
#
$(MPLAB_C18_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		 T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		 F=$(call GETVAL,$@,..\(...\)...\.lib,$(FAMILY_VALS)) \
		 M=$(call GETVAL,$@,.*\(.\)..\.lib,$(MODEL_VALS)) \
		 G=$(call GETVAL,$@,.*\(.\).\.lib,$(GLOBAL_VALS)) \
		 C=$(call GETVAL,$@,.*\(.\)\.lib,$(CONFIG_VALS)) \
		 V=OSNONE \
		 CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for IAR PIC18CXXX and PIC18 targets
#
$(IAR_PIC18_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		 T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		 F=$(call GETVAL,$@,..\(.....\).....\.r49,$(FAMILY_VALS)) \
		 O=$(call GETVAL,$@,.*\(.\)....\.r49,$(OPTION_VALS)) \
		 M=$(call GETVAL,$@,.*\(.\)..\.r49,$(MODEL_VALS)) \
		 G=$(call GETVAL,$@,.*\(.\).\.r49,$(GLOBAL_VALS)) \
		 C=$(call GETVAL,$@,.*\(.\)\.r49,$(CONFIG_VALS)) \
		 V=OSNONE \
		 CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for HI-TECH V8C
#
$(HT_V8C_cv8_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,..\(...\)..\.lib,$(FAMILY_VALS)) \
		C=$(call GETVAL,$@,.*\(.\).\.lib,$(CONFIG_VALS)) \
		V=$(call GETVAL,$@,.*\(.\)\.lib,$(VARIANT_VALS)) \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for GNU C (GCC) and 6811 targets
#
$(GCC_6811_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,...\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,.....\(.......\)..\.a,$(FAMILY_VALS)) \
		C=$(call GETVAL,$@,....*\(.\).\.a,$(CONFIG_VALS)) \
		V=$(call GETVAL,$@,....*\(.\)\.a,$(VARIANT_VALS)) \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for GNU C (GCC) and x86 targets
#
$(GCC_x86_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,...\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,.....\(......\)..\.a,$(FAMILY_VALS)) \
		C=$(call GETVAL,$@,....*\(.\).\.a,$(CONFIG_VALS)) \
		V=$(call GETVAL,$@,....*\(.\)\.a,$(VARIANT_VALS)) \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for GNU AVR-GCC C Compiler
#
$(GCC_AVR_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,...\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,.....\(......\)..\.a,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,....*\(.\).\.a,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,....*\(.\)\.a,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for Archelon / Quadravox AQ430 compiler
#
$(AQ_430_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,..\(.....\)..\.lib,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,.*\(.\).\.lib,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,.*\(.\)\.lib,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for Rowley Associates CrossWorks for MSP430 compiler
#
$(CS_430_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,...\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,.....\(.....\)..\.hza,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,....*\(.\).\.hza,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,....*\(.\)\.hza,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for ImageCraft ICC11 C compiler
#
$(ICC_11_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,...\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,.....\(.....\)..\.a,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,....*\(.\).\.a,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,....*\(.\)\.a,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for ImageCraft ICC430 C compiler
#
$(ICC_430_LIBRARIES) \
$(ICC_AVR_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,...\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,.....\(......\)..\.a,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,....*\(.\).\.a,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,....*\(.\)\.a,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)

$(ICC_ATMEGA_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,...\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,.....\(.........\)..\.a,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,....*\(.\).\.a,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,....*\(.\)\.a,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for IAR MSP430 compiler
#
$(IAR_430_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,..\(......\)..\.r43,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,.*\(.\).\.r43,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,.*\(.\)\.r43,$(CONFIG_VALS)) \
		V=OSNONE \
		CVER=$(CVER) \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for ZDSII EZ8 compiler
#
$(ZLG_EZ8_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,..\(...\)...\.lib,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,.*\(.\)..\.lib,$(OPTION_VALS)) \
		M=$(call GETVAL,$@,.*\(.\).\.lib,$(MODEL_VALS)) \
		C=$(call GETVAL,$@,.*\(.\)\.lib,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for TI C24X / C28X compiler
#
$(TI_C2400_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,..\(......\)..\.lib,$(FAMILY_VALS)) \
		O=$(call GETVAL,$@,.*\(.\).\.lib,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,.*\(.\)\.lib,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)

$(TI_C2800_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		F=$(call GETVAL,$@,..\(......\)...\.lib,$(FAMILY_VALS)) \
		M=$(call GETVAL,$@,.*\(.\)..\.lib,$(MODEL_VALS)) \
		O=$(call GETVAL,$@,.*\(.\).\.lib,$(OPTION_VALS)) \
		C=$(call GETVAL,$@,.*\(.\)\.lib,$(CONFIG_VALS)) \
		V=OSNONE \
		CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for KEIL C51 and 8051 targets
#
$(KEIL_C51_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		 T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		 F=$(call GETVAL,$@,..\(...\)....\.lib,$(FAMILY_VALS)) \
		 M=$(call GETVAL,$@,.*\(.\)...\.lib,$(MODEL_VALS)) \
		 G=$(call GETVAL,$@,.*\(.\)..\.lib,$(GLOBAL_VALS)) \
		 C=$(call GETVAL,$@,.*\(.\).\.lib,$(CONFIG_VALS)) \
		 V=$(call GETVAL,$@,.*\(.\)\.lib,$(VARIANT_VALS)) \
		 CLC=$(CLC)

$(KEIL_Cx51_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		 T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		 F=$(call GETVAL,$@,..\(....\)....\.lib,$(FAMILY_VALS)) \
		 M=$(call GETVAL,$@,.*\(.\)...\.lib,$(MODEL_VALS)) \
		 G=$(call GETVAL,$@,.*\(.\)..\.lib,$(GLOBAL_VALS)) \
		 C=$(call GETVAL,$@,.*\(.\).\.lib,$(CONFIG_VALS)) \
		 V=$(call GETVAL,$@,.*\(.\)\.lib,$(VARIANT_VALS)) \
		 CLC=$(CLC)


###########################################################################################
#
#   targets: libraries for HT C51 and 8051 targets
#
$(HT_C51_LIBRARIES) :
	$(MAKE) -f Makefile2 $@ \
		 T=$(call GETVAL,$@,\(..\),$(TYPE_VALS)) \
		 F=$(call GETVAL,$@,..\(..\)....\.lib,$(FAMILY_VALS))  \
		 M=$(call GETVAL,$@,.*\(.\)...\.lib,$(MODEL_VALS)) \
		 G=$(call GETVAL,$@,.*\(.\)..\.lib,$(GLOBAL_VALS)) \
		 C=$(call GETVAL,$@,.*\(.\).\.lib,$(CONFIG_VALS)) \
		 V=$(call GETVAL,$@,.*\(.\)\.lib,$(VARIANT_VALS)) \
		 CLC=$(CLC)


