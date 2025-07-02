#include "Timer.h"

void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) 
    {
        case DL_TIMER_IIDX_ZERO:
            DL_GPIO_togglePins(GPIO_LED_PORT,GPIO_LED_PIN_LED_1_PIN);
            break;
        default:
            break;
    }
}
