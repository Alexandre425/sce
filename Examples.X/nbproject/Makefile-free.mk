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
ifeq "$(wildcard nbproject/Makefile-local-free.mk)" "nbproject/Makefile-local-free.mk"
include nbproject/Makefile-local-free.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=free
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Labs/Lab01_HelloWorld/HelloWorld.c Labs/Lab02_Blink/Blink.c Labs/Lab03_Rotate/Rotate.c Labs/Lab04_AnalogToDigitalConversion/ADC.c Labs/Lab05_VariableSpeedRotate/VSR.c Labs/Lab06_PulseWidthModulation/PWM.c Labs/Lab07_Timers/Timer1.c Labs/Lab08_Interrupts/Interrupt.c Labs/Lab09_SleepWakeup/SleepWakeUp.c Labs/Lab10_EEPROM/EEPROM.c mcc_generated_files/interrupt_manager.c mcc_generated_files/tmr0.c mcc_generated_files/pwm6.c mcc_generated_files/mcc.c mcc_generated_files/device_config.c mcc_generated_files/memory.c mcc_generated_files/tmr1.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr2.c mcc_generated_files/adcc.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1 ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1 ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1 ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1 ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1 ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1 ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1 ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1 ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1 ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1 ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 ${OBJECTDIR}/mcc_generated_files/tmr0.p1 ${OBJECTDIR}/mcc_generated_files/pwm6.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/device_config.p1 ${OBJECTDIR}/mcc_generated_files/memory.p1 ${OBJECTDIR}/mcc_generated_files/tmr1.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/tmr2.p1 ${OBJECTDIR}/mcc_generated_files/adcc.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1.d ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1.d ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1.d ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1.d ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1.d ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1.d ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1.d ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1.d ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1.d ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d ${OBJECTDIR}/mcc_generated_files/pwm6.p1.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d ${OBJECTDIR}/mcc_generated_files/memory.p1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d ${OBJECTDIR}/mcc_generated_files/tmr2.p1.d ${OBJECTDIR}/mcc_generated_files/adcc.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1 ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1 ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1 ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1 ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1 ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1 ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1 ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1 ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1 ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1 ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 ${OBJECTDIR}/mcc_generated_files/tmr0.p1 ${OBJECTDIR}/mcc_generated_files/pwm6.p1 ${OBJECTDIR}/mcc_generated_files/mcc.p1 ${OBJECTDIR}/mcc_generated_files/device_config.p1 ${OBJECTDIR}/mcc_generated_files/memory.p1 ${OBJECTDIR}/mcc_generated_files/tmr1.p1 ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 ${OBJECTDIR}/mcc_generated_files/tmr2.p1 ${OBJECTDIR}/mcc_generated_files/adcc.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=Labs/Lab01_HelloWorld/HelloWorld.c Labs/Lab02_Blink/Blink.c Labs/Lab03_Rotate/Rotate.c Labs/Lab04_AnalogToDigitalConversion/ADC.c Labs/Lab05_VariableSpeedRotate/VSR.c Labs/Lab06_PulseWidthModulation/PWM.c Labs/Lab07_Timers/Timer1.c Labs/Lab08_Interrupts/Interrupt.c Labs/Lab09_SleepWakeup/SleepWakeUp.c Labs/Lab10_EEPROM/EEPROM.c mcc_generated_files/interrupt_manager.c mcc_generated_files/tmr0.c mcc_generated_files/pwm6.c mcc_generated_files/mcc.c mcc_generated_files/device_config.c mcc_generated_files/memory.c mcc_generated_files/tmr1.c mcc_generated_files/pin_manager.c mcc_generated_files/tmr2.c mcc_generated_files/adcc.c main.c



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
	${MAKE}  -f nbproject/Makefile-free.mk dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F18875
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1: Labs/Lab01_HelloWorld/HelloWorld.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab01_HelloWorld" 
	@${RM} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1 Labs/Lab01_HelloWorld/HelloWorld.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.d ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1: Labs/Lab02_Blink/Blink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab02_Blink" 
	@${RM} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1 Labs/Lab02_Blink/Blink.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.d ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1: Labs/Lab03_Rotate/Rotate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab03_Rotate" 
	@${RM} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1 Labs/Lab03_Rotate/Rotate.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.d ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1: Labs/Lab04_AnalogToDigitalConversion/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion" 
	@${RM} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1 Labs/Lab04_AnalogToDigitalConversion/ADC.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.d ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1: Labs/Lab05_VariableSpeedRotate/VSR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate" 
	@${RM} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1 Labs/Lab05_VariableSpeedRotate/VSR.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.d ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1: Labs/Lab06_PulseWidthModulation/PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab06_PulseWidthModulation" 
	@${RM} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1 Labs/Lab06_PulseWidthModulation/PWM.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.d ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1: Labs/Lab07_Timers/Timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab07_Timers" 
	@${RM} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1 Labs/Lab07_Timers/Timer1.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.d ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1: Labs/Lab08_Interrupts/Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab08_Interrupts" 
	@${RM} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1 Labs/Lab08_Interrupts/Interrupt.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.d ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1: Labs/Lab09_SleepWakeup/SleepWakeUp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab09_SleepWakeup" 
	@${RM} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1 Labs/Lab09_SleepWakeup/SleepWakeUp.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.d ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1: Labs/Lab10_EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab10_EEPROM" 
	@${RM} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1 Labs/Lab10_EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.d ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1: mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr0.p1: mcc_generated_files/tmr0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr0.p1 mcc_generated_files/tmr0.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr0.d ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pwm6.p1: mcc_generated_files/pwm6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm6.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm6.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pwm6.p1 mcc_generated_files/pwm6.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pwm6.d ${OBJECTDIR}/mcc_generated_files/pwm6.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pwm6.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/mcc.p1 mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/device_config.p1: mcc_generated_files/device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/device_config.p1 mcc_generated_files/device_config.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/device_config.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/memory.p1: mcc_generated_files/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/memory.p1 mcc_generated_files/memory.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/memory.d ${OBJECTDIR}/mcc_generated_files/memory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/memory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr1.p1: mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr1.p1 mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr2.p1: mcc_generated_files/tmr2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr2.p1 mcc_generated_files/tmr2.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr2.d ${OBJECTDIR}/mcc_generated_files/tmr2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/adcc.p1: mcc_generated_files/adcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/adcc.p1 mcc_generated_files/adcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/adcc.d ${OBJECTDIR}/mcc_generated_files/adcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/adcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1: Labs/Lab01_HelloWorld/HelloWorld.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab01_HelloWorld" 
	@${RM} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1 Labs/Lab01_HelloWorld/HelloWorld.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.d ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab01_HelloWorld/HelloWorld.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1: Labs/Lab02_Blink/Blink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab02_Blink" 
	@${RM} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1 Labs/Lab02_Blink/Blink.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.d ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab02_Blink/Blink.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1: Labs/Lab03_Rotate/Rotate.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab03_Rotate" 
	@${RM} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1 Labs/Lab03_Rotate/Rotate.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.d ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab03_Rotate/Rotate.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1: Labs/Lab04_AnalogToDigitalConversion/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion" 
	@${RM} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1 Labs/Lab04_AnalogToDigitalConversion/ADC.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.d ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab04_AnalogToDigitalConversion/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1: Labs/Lab05_VariableSpeedRotate/VSR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate" 
	@${RM} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1 Labs/Lab05_VariableSpeedRotate/VSR.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.d ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab05_VariableSpeedRotate/VSR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1: Labs/Lab06_PulseWidthModulation/PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab06_PulseWidthModulation" 
	@${RM} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1 Labs/Lab06_PulseWidthModulation/PWM.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.d ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab06_PulseWidthModulation/PWM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1: Labs/Lab07_Timers/Timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab07_Timers" 
	@${RM} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1 Labs/Lab07_Timers/Timer1.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.d ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab07_Timers/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1: Labs/Lab08_Interrupts/Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab08_Interrupts" 
	@${RM} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1 Labs/Lab08_Interrupts/Interrupt.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.d ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab08_Interrupts/Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1: Labs/Lab09_SleepWakeup/SleepWakeUp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab09_SleepWakeup" 
	@${RM} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1 Labs/Lab09_SleepWakeup/SleepWakeUp.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.d ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab09_SleepWakeup/SleepWakeUp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1: Labs/Lab10_EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Labs/Lab10_EEPROM" 
	@${RM} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1 Labs/Lab10_EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.d ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Labs/Lab10_EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1: mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1 mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr0.p1: mcc_generated_files/tmr0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr0.p1 mcc_generated_files/tmr0.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr0.d ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pwm6.p1: mcc_generated_files/pwm6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm6.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm6.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pwm6.p1 mcc_generated_files/pwm6.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pwm6.d ${OBJECTDIR}/mcc_generated_files/pwm6.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pwm6.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/mcc.p1: mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/mcc.p1 mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/mcc.d ${OBJECTDIR}/mcc_generated_files/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/device_config.p1: mcc_generated_files/device_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/device_config.p1 mcc_generated_files/device_config.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/device_config.d ${OBJECTDIR}/mcc_generated_files/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/memory.p1: mcc_generated_files/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/memory.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/memory.p1 mcc_generated_files/memory.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/memory.d ${OBJECTDIR}/mcc_generated_files/memory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/memory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr1.p1: mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr1.p1 mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr1.d ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/pin_manager.p1: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/pin_manager.p1 mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/pin_manager.d ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/tmr2.p1: mcc_generated_files/tmr2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/tmr2.p1 mcc_generated_files/tmr2.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/tmr2.d ${OBJECTDIR}/mcc_generated_files/tmr2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/tmr2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcc_generated_files/adcc.p1: mcc_generated_files/adcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adcc.p1.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adcc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/mcc_generated_files/adcc.p1 mcc_generated_files/adcc.c 
	@-${MV} ${OBJECTDIR}/mcc_generated_files/adcc.d ${OBJECTDIR}/mcc_generated_files/adcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcc_generated_files/adcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_free=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_free=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c90 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.map  -DXPRJ_free=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Examples.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/free
	${RM} -r dist/free

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
