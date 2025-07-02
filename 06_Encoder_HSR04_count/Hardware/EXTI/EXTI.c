#include "EXTI.h"


int Get_count(void)
{
    return number;
}
void GROUP1_IRQHandler(void)
{
    uint32_t Encoder_A=DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT,GPIO_Encoder_PIN_A_PIN);
    uint32_t Echo=DL_GPIO_getEnabledInterruptStatus(GPIO_HSR04_PORT,GPIO_HSR04_PIN_Echo_PIN);
    //1.A相触发
    if((Encoder_A & GPIO_Encoder_PIN_A_PIN)==GPIO_Encoder_PIN_A_PIN)
    {
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_PIN_A_PIN);
        if(DL_GPIO_readPins(GPIO_Encoder_PORT,GPIO_Encoder_PIN_A_PIN))//A相上升沿
        {
           if(DL_GPIO_readPins(GPIO_Encoder_PORT,GPIO_Encoder_PIN_B_PIN))//B相高电平
                number--;
           else 
                number++;
        }
        else//A下降沿
        {
            if(DL_GPIO_readPins(GPIO_Encoder_PORT,GPIO_Encoder_PIN_B_PIN))//B相高电平
                number++;
            else 
                number--;
         }
    }
        // 2.超声波触发
    else if((Echo & GPIO_HSR04_PIN_Echo_PIN)==GPIO_HSR04_PIN_Echo_PIN)
    {
        DL_GPIO_clearInterruptStatus(GPIO_HSR04_PORT, GPIO_HSR04_PIN_Echo_PIN);
        if(DL_GPIO_readPins(GPIO_HSR04_PORT,GPIO_HSR04_PIN_Echo_PIN))//高电平
        {
            HSR04_Count  ++;
            // DL_TimerG_setTimerCount(TIMER_Ultrasonic_INST, 0);
            // DL_TimerG_startCounter(TIMER_Ultrasonic_INST);
        }
        else//低电平
        {
            HSR04_Count++;
        }
    }


}
