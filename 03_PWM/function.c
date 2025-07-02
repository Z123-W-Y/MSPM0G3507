#include "function.h"

void All_Interrupt(void)
{
    //1.开启定时器计时中断
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    DL_TimerG_startCounter(TIMER_0_INST);


}

