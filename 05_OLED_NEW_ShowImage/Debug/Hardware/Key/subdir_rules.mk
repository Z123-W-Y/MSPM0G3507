################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/Key/%.o: ../Hardware/Key/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/OLED" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/EXTI" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/HSR04" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/MPU6050" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/MSPM0" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/ADC" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware/PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowImage/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"Hardware/Key/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


