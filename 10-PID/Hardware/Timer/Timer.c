#include "Timer.h"

//

void TIMER_0_INST_IRQHandler(void)//100ms进一次中断,编码器测速
{
    if(DL_TimerG_getPendingInterrupt(TIMER_0_INST)==DL_TIMER_IIDX_ZERO)
    {
        MOTOR.Count_L=Encoder_L_Data;
        MOTOR.Count_R=Encoder_R_Data;
        Encoder_L_Data=0;
        Encoder_R_Data=0;
    }
}
