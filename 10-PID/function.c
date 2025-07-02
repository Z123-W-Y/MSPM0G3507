#include "function.h"

void All_Interrupt(void)
{
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);//UART0中断

    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);//开启按键引脚的GPIOA端口中断 超声波/编码器
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);//开启按键引脚的GPIOB端口中断 MPU6050/编码器
     
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);//开启定时器计时中断
    DL_TimerG_startCounter(TIMER_0_INST);

    NVIC_EnableIRQ(TIMER_HSR04_INST_INT_IRQN);//超声波定时器

    NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);//ADC中断

}

void PID_Num_Init(void)
{
    PID_Init(&PID_L,0.05f,0.0f,0.0f);//初始化pid参数
    PID_L.deadzone_in=0;//输入死区
    PID_L.limit_integral=4000;//积分限幅

    // PID_R.deadzone_in=20;
    // PID_L.limit_integral=200;
    // PID_Init(&PID_R,1.0f,0.1f,0.0f);//初始化pid参数
}