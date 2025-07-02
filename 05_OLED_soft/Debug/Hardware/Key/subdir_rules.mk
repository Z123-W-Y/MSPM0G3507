################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/Key/%.o: ../Hardware/Key/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/Hardware/OLED" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_soft/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"Hardware/Key/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


