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

uint8_t oled_buffer[72];
char uart_buffer[72];

//Kp=2.2,ki=0.2,kd=0
PID_Typedef PID_L;//左电机PID
PID_Typedef PID_R;//右电机PID
PIDOUT_Typedef PIDOUT_L;//左电机PID输出
PIDOUT_Typedef PIDOUT_R;//右电机PID输出

VOFA_Typedef VOFA;//上位机
Motor_Typedef MOTOR;//电机脉冲数

DIR_Typedef DIR;//枚举方向


volatile float DATA_L=0.0;
volatile float DATA_R;


int main(void)
{
    SYSCFG_DL_init();
    All_Interrupt();
    OLED_Init();
    mpu6050_init();
    PID_Num_Init();

    OLED_ShowString(0,1,(uint8_t *)"Pitch:",8);
    OLED_ShowString(0,2,(uint8_t *)" Roll:",8);
    OLED_ShowString(0,3,(uint8_t *)"  Yaw:",8);

    ////步进电机
    // DL_GPIO_clearPins(GPIO_Step_Motor_PORT, GPIO_Step_Motor_PIN_ENA_PIN);
    // DL_GPIO_setPins(GPIO_Step_Motor_PORT, GPIO_Step_Motor_PIN_DIR_PIN);
    // while (1)
    // {
    //     DL_GPIO_clearPins(GPIO_Step_Motor_PORT, GPIO_Step_Motor_PIN_STEP_PIN);
    //     Delay_us(100);
    //     DL_GPIO_setPins(GPIO_Step_Motor_PORT, GPIO_Step_Motor_PIN_STEP_PIN);
    //     Delay_us(100);
    // }
    while (1) 
    {
        // DL_ADC12_startConversion(ADC12_0_INST);//开启ADC采样

        // //编码电机脉冲数，超声波距离
        // memset(oled_buffer,0,72);
        // sprintf(str,"num=%04d,S=%.2f",Encoder_L_Data,Get_Juli());
        // OLED_ShowString(0, 0, (uint8_t*)str, 8);
        // Trig_HL();

        //MPU6050显示
        memset(oled_buffer,0,72);
        sprintf((char *)oled_buffer, "%6.1f", pitch);
        OLED_ShowString(7*8,1,oled_buffer,8);

        memset(oled_buffer,0,72);
        sprintf((char *)oled_buffer, "%6.1f", roll);
        OLED_ShowString(7*8,2,oled_buffer,8);

        memset(oled_buffer,0,72);
        sprintf((char *)oled_buffer, "%6.1f", yaw);
        OLED_ShowString(7*8,3,oled_buffer,8);


        char str[] = "12.567,32.345,123";
        float x1,x2;
        int num;
        sscanf(str, "%f,%f,%d",&x1,&x2, &num);  // 只读取3位：num=123
        memset(oled_buffer,0,72);
        sprintf((char *)oled_buffer, "%.2f,%.2f,%d", x1,x2,num);
        OLED_ShowString(0,4,oled_buffer,8);

        // PID计算
        DATA_L=PID_Positional(&PID_L,&PIDOUT_L,MOTOR.Count_L,150.0,1.0f);
        PWM_Duty(1,DATA_L);

        memset(uart_buffer,0,72);
        sprintf(uart_buffer,"%f\r\n",(float)MOTOR.Count_L);
        UART0_SendString(uart_buffer);


        //ADC
        // memset(oled_buffer,0,72);
        // sprintf(oled_buffer,"ADC=%d",Get_ADC_Val());//正点原子上位机发送格式
        // OLED_ShowString(7*8,7,(uint8_t *)oled_buffer,8);

        //按键
        int key=KeyScan();
        if(key==2)
        {
            // // pwm=100;
            // PWM_Duty(1,0);
            DL_GPIO_setPins(GPIO_Step_Motor_PORT, GPIO_Step_Motor_PIN_ENA_PIN);
        }
        else if(key==3)
        {
            // // pwm=-100;
            // PWM_Duty(1,10);
            DL_GPIO_clearPins(GPIO_Step_Motor_PORT, GPIO_Step_Motor_PIN_ENA_PIN);
        }
        else if(key==4)
        {
            // pwm=-100;
            PWM_Duty(1,300);
        }
        else if(key==5)
        {
            // pwm=-100;
            PWM_Duty(1,1000);
        }
    }
}

