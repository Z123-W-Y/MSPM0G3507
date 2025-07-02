#include "function.h"

void All_Interrupt(void)
{
    //UART0中断
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);


    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);//开启按键引脚的GPIOA端口中断
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);//开启按键引脚的GPIOB端口中断

     //开启定时器计时中断
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    DL_TimerG_startCounter(TIMER_0_INST);

    NVIC_EnableIRQ(TIMER_HSR04_INST_INT_IRQN);//超声波定时器

}

