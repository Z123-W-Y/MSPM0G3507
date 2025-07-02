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
uint8_t mpu6050_int_flag = 0;
uint8_t oled_buffer[16];
int Encoder_count = 0;
int timer_flag=0;
float Encoder_V=0.0;//电机速度
int main(void)
{
    SYSCFG_DL_init();
    All_Interrupt();
    OLED_Init();
    OLED_Clear();
    mpu6050_init();

    OLED_ShowString(0,0,(uint8_t *)"Pitch:",16);
    OLED_ShowString(0,2,(uint8_t *)" Roll:",16);
    OLED_ShowString(0,4,(uint8_t *)"  Yaw:",16);
    while (1) 
    {
        if(mpu6050_int_flag)
        {
            mpu6050_int_flag = 0;
            Read_Quad();
            sprintf((char *)oled_buffer, "%6.1f", pitch);
            OLED_ShowString(7*8,0,oled_buffer,16);
            sprintf((char *)oled_buffer, "%6.1f", roll);
            OLED_ShowString(7*8,2,oled_buffer,16);
            sprintf((char *)oled_buffer, "%6.1f", yaw);
            OLED_ShowString(7*8,4,oled_buffer,16);
        }
        if(timer_flag>15)
        {
            timer_flag=0;
            // OLED_Clear();
            Trig_HL();
        }
        char str[20];
        memset(str,0,20);
        sprintf(str,"num=%04d,S=%.3f",Encoder_count,Get_Juli());
        OLED_ShowString(0, 6, (uint8_t*)str, 8);
        memset(str,0,20);
        sprintf(str,"V:%.2f",Encoder_V);
        OLED_ShowString(0, 7, (uint8_t*)str, 8);
        if(KeyScan()==1)
        {
            LED_TIG();

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




