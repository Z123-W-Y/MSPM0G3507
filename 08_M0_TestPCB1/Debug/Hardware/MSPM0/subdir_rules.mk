################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/MSPM0/%.o: ../Hardware/MSPM0/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/System" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/Key" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/PWM" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/UART" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/OLED" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/EXTI" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/Timer" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/HSR04" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/MPU6050" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware/MSPM0" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Hardware" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1" -I"D:/sys/MSPM0G3507/M0G3507_TestPCB/M0_TestPCB1/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"Hardware/MSPM0/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


