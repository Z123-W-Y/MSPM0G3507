################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/ADC/%.o: ../Hardware/ADC/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action/System" -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action/Hardware/Key" -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action/Hardware/Timer" -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action/Hardware/PWM" -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action/Hardware/ADC" -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action/Hardware" -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action" -I"D:/sys/MSPM0G3507/M0G3507_CCS/M0G3507_Mode_Project/Action/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"Hardware/ADC/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


