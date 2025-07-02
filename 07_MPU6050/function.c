#include "function.h"

void All_Interrupt(void)
{
    //1.开启定时器计时中断
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    DL_TimerG_startCounter(TIMER_0_INST);

    //2.UART中断
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
    
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);//编码器/超声波Echo/MPU6050INT中断
    NVIC_EnableIRQ(TIMER_HSR04_INST_INT_IRQN);//超声波定时器中断



}

