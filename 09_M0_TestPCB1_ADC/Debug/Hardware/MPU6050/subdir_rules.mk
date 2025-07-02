################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/MPU6050/%.o: ../Hardware/MPU6050/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/OLED" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/EXTI" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/HSR04" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/MPU6050" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/MSPM0" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware/ADC" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC" -I"D:/MSPM0G3507/M0G3507_Mode_Project/09_M0_TestPCB1_ADC/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"Hardware/MPU6050/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


