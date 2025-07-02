################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-492501215: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/TI/sysconfig_1.22.0/sysconfig_cli.bat" --script "D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/empty.syscfg" -o "." -s "C:/TI/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-492501215 ../empty.syscfg
device.opt: build-492501215
device.cmd.genlibs: build-492501215
ti_msp_dl_config.c: build-492501215
ti_msp_dl_config.h: build-492501215
Event.dot: build-492501215

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/OLED" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/EXTI" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/HSR04" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/MPU6050" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/MSPM0" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/ADC" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/TI/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/OLED" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/EXTI" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/HSR04" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/MPU6050" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/MSPM0" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/ADC" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/OLED" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/EXTI" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/HSR04" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/MPU6050" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/MSPM0" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/ADC" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware/PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/10-PID/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


