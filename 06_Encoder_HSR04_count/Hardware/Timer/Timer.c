#include "Timer.h"

//
void TIMER_0_INST_IRQHandler(void)//500ms进一次中断,编码器测速
{
    if(DL_TimerG_getPendingInterrupt(TIMER_0_INST)==DL_TIMER_IIDX_ZERO)
    {

        timer_flag++;

        number=0;
    }
}
