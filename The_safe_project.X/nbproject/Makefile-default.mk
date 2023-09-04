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
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/ecu_button/ecu_button.c ECU_Layer/ecu_buzzer/ecu_buzzer.c ECU_Layer/ecu_dc_motor/ecu_dc_motor.c ECU_Layer/ecu_keypad/ecu_keypad.c ECU_Layer/ecu_lcd/ecu_lcd.c ECU_Layer/ecu_led/ecu_led.c ECU_Layer/ecu_initialize.c MCAL_Layer/DIO/HAL_GPIO.c MCAL_Layer/EEPROM/mcal_eeprom.c App.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1 ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 ${OBJECTDIR}/App.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1.d ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1.d ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1.d ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d ${OBJECTDIR}/App.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1 ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 ${OBJECTDIR}/App.p1

# Source Files
SOURCEFILES=ECU_Layer/ecu_button/ecu_button.c ECU_Layer/ecu_buzzer/ecu_buzzer.c ECU_Layer/ecu_dc_motor/ecu_dc_motor.c ECU_Layer/ecu_keypad/ecu_keypad.c ECU_Layer/ecu_lcd/ecu_lcd.c ECU_Layer/ecu_led/ecu_led.c ECU_Layer/ecu_initialize.c MCAL_Layer/DIO/HAL_GPIO.c MCAL_Layer/EEPROM/mcal_eeprom.c App.c



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
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1: ECU_Layer/ecu_button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1 ECU_Layer/ecu_button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.d ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1: ECU_Layer/ecu_buzzer/ecu_buzzer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_buzzer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ECU_Layer/ecu_buzzer/ecu_buzzer.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.d ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1: ECU_Layer/ecu_dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1 ECU_Layer/ecu_dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1: ECU_Layer/ecu_keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ECU_Layer/ecu_keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.d ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1: ECU_Layer/ecu_lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_lcd" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ECU_Layer/ecu_lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.d ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1: ECU_Layer/ecu_led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_led" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ECU_Layer/ecu_led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.d ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_initialize.p1: ECU_Layer/ecu_initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ECU_Layer/ecu_initialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_initialize.d ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1: MCAL_Layer/DIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1 MCAL_Layer/DIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1: MCAL_Layer/EEPROM/mcal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 MCAL_Layer/EEPROM/mcal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/App.p1: App.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/App.p1.d 
	@${RM} ${OBJECTDIR}/App.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App.p1 App.c 
	@-${MV} ${OBJECTDIR}/App.d ${OBJECTDIR}/App.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1: ECU_Layer/ecu_button/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1 ECU_Layer/ecu_button/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.d ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_button/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1: ECU_Layer/ecu_buzzer/ecu_buzzer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_buzzer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ECU_Layer/ecu_buzzer/ecu_buzzer.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.d ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1: ECU_Layer/ecu_dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1 ECU_Layer/ecu_dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1: ECU_Layer/ecu_keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ECU_Layer/ecu_keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.d ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1: ECU_Layer/ecu_lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_lcd" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ECU_Layer/ecu_lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.d ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1: ECU_Layer/ecu_led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_led" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ECU_Layer/ecu_led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.d ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_initialize.p1: ECU_Layer/ecu_initialize.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1 ECU_Layer/ecu_initialize.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_initialize.d ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_initialize.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1: MCAL_Layer/DIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/DIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1 MCAL_Layer/DIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/DIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1: MCAL_Layer/EEPROM/mcal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1 MCAL_Layer/EEPROM/mcal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.d ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EEPROM/mcal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/App.p1: App.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/App.p1.d 
	@${RM} ${OBJECTDIR}/App.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App.p1 App.c 
	@-${MV} ${OBJECTDIR}/App.d ${OBJECTDIR}/App.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/The_safe_project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
