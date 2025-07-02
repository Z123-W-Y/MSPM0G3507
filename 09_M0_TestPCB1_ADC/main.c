/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "main.h"
int Encoder_L_Data=0;
int Encoder_R_Data=0;
uint8_t oled_buffer[32];

int main(void)
{
    SYSCFG_DL_init();
    All_Interrupt();
    OLED_Init();
    mpu6050_init();

    OLED_ShowString(0,1,(uint8_t *)"Pitch:",8);
    OLED_ShowString(0,2,(uint8_t *)" Roll:",8);
    OLED_ShowString(0,3,(uint8_t *)"  Yaw:",8);

    while (1) 
    {
        DL_ADC12_startConversion(ADC12_0_INST);//开启ADC采样

        char str[20];
        sprintf(str,"num=%04d,S=%.2f",Encoder_L_Data,Get_Juli());
        OLED_ShowString(0, 0, (uint8_t*)str, 8);
        Trig_HL();
        sprintf((char *)oled_buffer, "%6.1f", pitch);
        OLED_ShowString(7*8,1,oled_buffer,8);
        sprintf((char *)oled_buffer, "%6.1f", roll);
        OLED_ShowString(7*8,2,oled_buffer,8);
        sprintf((char *)oled_buffer, "%6.1f", yaw);
        OLED_ShowString(7*8,3,oled_buffer,8);



        int key=KeyScan();
        if(key==1)
        {
            LED_TIG();
            BUZZ_TIG();

        }
        else if(key==2)
        {
            PWM_Duty(1,100);
        }
        else if(key==3)
        {

            PWM_Duty(1,500);
        }
        if(UART0_GetFlag())
        {
            UART0_SendByte(0x01);
            char str[20];
            sprintf(str,"a=%d,b=%x",12,34);
            UART0_SendString(str);
        }
    }
}

