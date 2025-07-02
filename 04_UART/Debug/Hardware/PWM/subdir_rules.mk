################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/PWM/%.o: ../Hardware/PWM/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/04_UART/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"Hardware/PWM/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


