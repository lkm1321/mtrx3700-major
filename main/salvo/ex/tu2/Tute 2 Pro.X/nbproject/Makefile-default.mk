#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Tute_2_Pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Tute_2_Pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../../../../../lib/salvo/src/init.c ../../../../../../../lib/salvo/src/inittask.c ../../../../../../../lib/salvo/src/mem.c ../../../../../../../lib/salvo/src/portpic18.c ../../../../../../../lib/salvo/src/qins.c ../../../../../../../lib/salvo/src/sched.c ../main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1971946829/init.o ${OBJECTDIR}/_ext/1971946829/inittask.o ${OBJECTDIR}/_ext/1971946829/mem.o ${OBJECTDIR}/_ext/1971946829/portpic18.o ${OBJECTDIR}/_ext/1971946829/qins.o ${OBJECTDIR}/_ext/1971946829/sched.o ${OBJECTDIR}/_ext/1472/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1971946829/init.o.d ${OBJECTDIR}/_ext/1971946829/inittask.o.d ${OBJECTDIR}/_ext/1971946829/mem.o.d ${OBJECTDIR}/_ext/1971946829/portpic18.o.d ${OBJECTDIR}/_ext/1971946829/qins.o.d ${OBJECTDIR}/_ext/1971946829/sched.o.d ${OBJECTDIR}/_ext/1472/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1971946829/init.o ${OBJECTDIR}/_ext/1971946829/inittask.o ${OBJECTDIR}/_ext/1971946829/mem.o ${OBJECTDIR}/_ext/1971946829/portpic18.o ${OBJECTDIR}/_ext/1971946829/qins.o ${OBJECTDIR}/_ext/1971946829/sched.o ${OBJECTDIR}/_ext/1472/main.o

# Source Files
SOURCEFILES=../../../../../../../lib/salvo/src/init.c ../../../../../../../lib/salvo/src/inittask.c ../../../../../../../lib/salvo/src/mem.c ../../../../../../../lib/salvo/src/portpic18.c ../../../../../../../lib/salvo/src/qins.c ../../../../../../../lib/salvo/src/sched.c ../main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Tute_2_Pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F452
MP_PROCESSOR_OPTION_LD=18f452
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1971946829/init.o: ../../../../../../../lib/salvo/src/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/init.o   ../../../../../../../lib/salvo/src/init.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/inittask.o: ../../../../../../../lib/salvo/src/inittask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/inittask.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/inittask.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/inittask.o   ../../../../../../../lib/salvo/src/inittask.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/inittask.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/inittask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/mem.o: ../../../../../../../lib/salvo/src/mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/mem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/mem.o   ../../../../../../../lib/salvo/src/mem.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/portpic18.o: ../../../../../../../lib/salvo/src/portpic18.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/portpic18.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/portpic18.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/portpic18.o   ../../../../../../../lib/salvo/src/portpic18.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/portpic18.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/portpic18.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/qins.o: ../../../../../../../lib/salvo/src/qins.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/qins.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/qins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/qins.o   ../../../../../../../lib/salvo/src/qins.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/qins.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/qins.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/sched.o: ../../../../../../../lib/salvo/src/sched.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/sched.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/sched.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/sched.o   ../../../../../../../lib/salvo/src/sched.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/sched.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/sched.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1971946829/init.o: ../../../../../../../lib/salvo/src/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/init.o   ../../../../../../../lib/salvo/src/init.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/inittask.o: ../../../../../../../lib/salvo/src/inittask.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/inittask.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/inittask.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/inittask.o   ../../../../../../../lib/salvo/src/inittask.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/inittask.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/inittask.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/mem.o: ../../../../../../../lib/salvo/src/mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/mem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/mem.o   ../../../../../../../lib/salvo/src/mem.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/portpic18.o: ../../../../../../../lib/salvo/src/portpic18.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/portpic18.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/portpic18.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/portpic18.o   ../../../../../../../lib/salvo/src/portpic18.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/portpic18.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/portpic18.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/qins.o: ../../../../../../../lib/salvo/src/qins.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/qins.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/qins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/qins.o   ../../../../../../../lib/salvo/src/qins.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/qins.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/qins.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1971946829/sched.o: ../../../../../../../lib/salvo/src/sched.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1971946829 
	@${RM} ${OBJECTDIR}/_ext/1971946829/sched.o.d 
	@${RM} ${OBJECTDIR}/_ext/1971946829/sched.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1971946829/sched.o   ../../../../../../../lib/salvo/src/sched.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1971946829/sched.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1971946829/sched.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -DSYSE -DMAKE_WITH_SOURCE -I"../" -I"../../../../../../../lib/salvo/inc" -ms -oa- -o- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Tute_2_Pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.Tute_2_Pro.X.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Tute_2_Pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/Tute_2_Pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.Tute_2_Pro.X.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Tute_2_Pro.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
