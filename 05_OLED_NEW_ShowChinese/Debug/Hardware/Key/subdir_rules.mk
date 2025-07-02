################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Hardware/Key/%.o: ../Hardware/Key/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/install/ccs_install/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/System" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/Key" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/PWM" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/UART" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/OLED" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/EXTI" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/Timer" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/HSR04" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/MPU6050" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/MSPM0" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/ADC" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware/PID" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Hardware" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese" -I"D:/MSPM0G3507/M0G3507_Mode_Project/05_OLED_NEW_ShowChinese/Debug" -I"C:/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/TI/mspm0_sdk_2_04_00_06/source" -DMPU6050 -DMOTION_DRIVER_TARGET_MSPM0 -gdwarf-3 -MMD -MP -MF"Hardware/Key/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


