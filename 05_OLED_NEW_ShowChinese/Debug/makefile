################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS

GEN_OPTS__FLAG := @"./device.opt" 
GEN_CMDS__FLAG := -Wl,-l"./device_linker.cmd" 

ORDERED_OBJS += \
"./ti_msp_dl_config.o" \
"./startup_mspm0g350x_ticlang.o" \
"./function.o" \
"./main.o" \
"./Hardware/ADC/ADC.o" \
"./Hardware/EXTI/EXTI.o" \
"./Hardware/HSR04/HSR04.o" \
"./Hardware/Key/Key.o" \
"./Hardware/MPU6050/inv_mpu.o" \
"./Hardware/MPU6050/inv_mpu_dmp_motion_driver.o" \
"./Hardware/MPU6050/mpu6050.o" \
"./Hardware/MPU6050/mspm0_clock.o" \
"./Hardware/MPU6050/mspm0_i2c.o" \
"./Hardware/OLED/OLED_Data.o" \
"./Hardware/OLED/oled.o" \
"./Hardware/PID/PID.o" \
"./Hardware/PWM/PWM.o" \
"./Hardware/Timer/Timer.o" \
"./Hardware/UART/UART.o" \
"./System/Delay.o" \
$(GEN_CMDS__FLAG) \
-Wl,-ldevice.cmd.genlibs \
-Wl,-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Hardware/ADC/subdir_vars.mk
-include Hardware/EXTI/subdir_vars.mk
-include Hardware/HSR04/subdir_vars.mk
-include Hardware/Key/subdir_vars.mk
-include Hardware/MPU6050/subdir_vars.mk
-include Hardware/OLED/subdir_vars.mk
-include Hardware/PID/subdir_vars.mk
-include Hardware/PWM/subdir_vars.mk
-include Hardware/Timer/subdir_vars.mk
-include Hardware/UART/subdir_vars.mk
-include System/subdir_vars.mk
-include subdir_rules.mk
-include Hardware/ADC/subdir_rules.mk
-include Hardware/EXTI/subdir_rules.mk
-include Hardware/HSR04/subdir_rules.mk
-include Hardware/Key/subdir_rules.mk
-include Hardware/MPU6050/subdir_rules.mk
-include Hardware/OLED/subdir_rules.mk
-include Hardware/PID/subdir_rules.mk
-include Hardware/PWM/subdir_rules.mk
-include Hardware/Timer/subdir_rules.mk
-include Hardware/UART/subdir_rules.mk
-include System/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
05_OLED_NEW_ShowChinese.out 

EXE_OUTPUTS__QUOTED += \
"05_OLED_NEW_ShowChinese.out" 


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "05_OLED_NEW_ShowChinese.out"

# Tool invocations
05_OLED_NEW_ShowChinese.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -Wl,-m"05_OLED_NEW_ShowChinese.map" -Wl,-i"C:/TI/mspm0_sdk_2_04_00_06/source" -Wl,-i"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese" -Wl,-i"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Debug/syscfg" -Wl,-i"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/lib" -Wl,--diag_wrap=off -Wl,--display_error_number -Wl,--warn_sections -Wl,--xml_link_info="05_OLED_NEW_ShowChinese_linkInfo.xml" -Wl,--rom_model -o "05_OLED_NEW_ShowChinese.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "ti_msp_dl_config.o" "startup_mspm0g350x_ticlang.o" "function.o" "main.o" "Hardware\ADC\ADC.o" "Hardware\EXTI\EXTI.o" "Hardware\HSR04\HSR04.o" "Hardware\Key\Key.o" "Hardware\MPU6050\inv_mpu.o" "Hardware\MPU6050\inv_mpu_dmp_motion_driver.o" "Hardware\MPU6050\mpu6050.o" "Hardware\MPU6050\mspm0_clock.o" "Hardware\MPU6050\mspm0_i2c.o" "Hardware\OLED\OLED_Data.o" "Hardware\OLED\oled.o" "Hardware\PID\PID.o" "Hardware\PWM\PWM.o" "Hardware\Timer\Timer.o" "Hardware\UART\UART.o" "System\Delay.o" 
	-$(RM) "ti_msp_dl_config.d" "startup_mspm0g350x_ticlang.d" "function.d" "main.d" "Hardware\ADC\ADC.d" "Hardware\EXTI\EXTI.d" "Hardware\HSR04\HSR04.d" "Hardware\Key\Key.d" "Hardware\MPU6050\inv_mpu.d" "Hardware\MPU6050\inv_mpu_dmp_motion_driver.d" "Hardware\MPU6050\mpu6050.d" "Hardware\MPU6050\mspm0_clock.d" "Hardware\MPU6050\mspm0_i2c.d" "Hardware\OLED\OLED_Data.d" "Hardware\OLED\oled.d" "Hardware\PID\PID.d" "Hardware\PWM\PWM.d" "Hardware\Timer\Timer.d" "Hardware\UART\UART.d" "System\Delay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

