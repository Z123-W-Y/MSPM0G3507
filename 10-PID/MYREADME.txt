示例代码中
    LED:
        LED1-PB22(高电平点亮)
        
    KEY:
        S1-PB21 SW2-PB17 SW3-PB18 SW4-PB19 SW5-PB20(低电平按下)

    BUZZ:
        BUZZ_1-PB1(低电平触发)

    Mort:
        APWM-PB5(L通道1)  BPWM-PB4(R通道0)
        AIN1-PB13 AN2-PB12
        BIN1-PB26 BIN2-PB27
    OLED:
        SCL-PA31 SDA-PA28(在移植的过程,要使OLED正常使用,要配置,防止编译器优化的模式,设为O0)
    Timer:
        TimerA0
        TimerG0
    Encoder:
        LA-PB14 LB-PA15
        RA-PA01  RB-PA07
        MG513P30单相上升沿-390脉冲/转
                     单相双边沿-780脉冲/转
                    双边双向脉冲-1560/转
    HSR04
        Trig-PA8(10us高电平发出波)
        Echo-PA9(接收回波)

    MPU6050:
        硬件I2C0(SCL-PA17,SDA-PA16),外部中断线INT-PB0
        MOTION_DRIVER_TARGET_MSPM0
        MPU6050
        x-Pitch-俯仰角   y-Roll-横滚角  z-Yaw-偏航角
    需要在工程选项中宏定义上面的内容才能使用mpu6050的移植

    ADC:
        PA27.ADC12_0_chnal0
        要开时钟数

sprintf的使用,包含<string.h>

    uint8_t oled_buffer[72];
    char uart_buffer[72];

    extern uint8_t oled_buffer[72];
    extern char uart_buffer[72];

    //OLED 显示
        memset(oled_buffer,0,72);
        sprintf((char *)oled_buffer, "%6.1f\n", pitch);//会自动补'\0'终止符
        OLED_ShowString(7*8,1,oled_buffer,8);


    //串口发送
            memset(uart_buffer,0,72);
            sprintf(uart_buffer,"%f\r\n",(float)MOTOR.Count_L);
            UART0_SendString(uart_buffer);
sscanf的使用,包含<stdio.h>,可以用于串口接收,防止丢包
        char str[] = "12.567,32.345,123";//这个数组的内容可以通过串口接收得到
        float x1,x2;
        int num;
        sscanf(str, "%f,%f,%d",&x1,&x2, &num);  // 只读取3位:num=123

        memset(oled_buffer,0,72);
        sprintf((char *)oled_buffer, "%.2f,%.2f,%d\0", x1,x2,num);//会自动补'\0'终止符
        OLED_ShowString(0,4,oled_buffer,8);


TIMG0_C0(PA12/PA23/PA5/PB10)
TIMG0_C1(PA13/PA24/PA6/PB11)

TIMG6_C0(PA21/PB26/PA29/PA5/PB2/PB6/PB10)
TIMG6_C1(PA22/PB27/PA30/PA6/PB3/PB7/PB11)

TIMG7_C0(PB15/PA17/PA23/PA26/PA28/PA3)
TIMG7_C1(PB16/PA18/PB19/PA24/PA27/PA31/PA2/PA4/PA7)

TIMG8_C0(PB15/PA21/PB21/PA23/PA26/PA1/PA29/PA3/PA5/PA7/PB6/PB10)
TIMG8_C1(PB16/PB19/PA22/PB22/PA27/PA0/PA30/PA2/PA4/PA6/PB7/PB11)

TIMG12_C0(PB13/PA14/PB20/PA10)
TIMG12_C1(PB14/PB24/PA25/PA31)

//TIMA系列的为高级定时器
TIMA0_C0(PB14/PA21/PA0/PA8/PB8)
TIMA0_C1(PA22/PA1/PA3/PA7/PA9/PB9/PB12)
TIMA0_C2(PA15/PB17/PB20/PA3/PB0/PA7/PB4/PA10/PB12)
TIMA0_C3(PB13/PA12/PA17/PB24/PA23/PA25/PB26/PA28/pa4/pb2)

TIMA1_C0(PA15/PA17/PB17/PB26/PA28/PB0/PB2/PA10)
TIMA1_C1(PA16/PA18/PB18/PA24/PB27/PA31/PB1/PB3/PB5/PA11)

UART0_TX(PA00/PA28/PB00/PA10)
UART0_RX(PA01/PA31/PB01/PA11)

UART1_TX(PA17/PB04/PA08/PB06)
UART1_RX(PA18/PB05/PA09/PB07)

UART2_TX(PB15/PB17/PA21/PA23)
UART2_Rx(PB16/PB18/PA22/PA24)

UART3_TX(PA14/PA26/PB02/PB12)
UART3_RX(PB13/PA13/PA25/PB03)

A0_0-PA27	A1_0-PA15
A0_1-PA26	A1_1-PA16
A0_2-PA25	A1_2-PA17
A0_3-PA24	A1_2-PA18
A0_4-PB25	A1_4-PB17
A0_5-PB24	A1_5-PB18
A0_6-PB20	A1_6-PB19
A0_7-PA22	A1_7-PA21
A0_12-PA14

I2C0_SCL(PA1/PA31PA11)
I2C0_SDA(PA0/PA28/PA10)

I2C1_SCL(PA15/PA17/PA29/PA4/PB2/PA11)
I2C1_SDA(PA16/PA18/PA30/PA3/PB3/PA10)