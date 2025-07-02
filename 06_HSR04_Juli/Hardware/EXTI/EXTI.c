#include "EXTI.h"

float dist=0;//超声波距离,计次
int overflowFlag=0;//超时不测
int cnt=0;

float Get_Juli(void)
{
    return dist;
}

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
        if(DL_GPIO_readPins(GPIO_HSR04_PORT,GPIO_HSR04_PIN_Echo_PIN))//上升沿
        {
            overflowFlag = 0;
            DL_TimerG_setTimerCount(TIMER_HSR04_INST, 0);
            DL_TimerG_startCounter(TIMER_HSR04_INST);
        }
        else//下降沿
        {
            if(overflowFlag)
            {
                dist = 0;
            }
            DL_TimerG_stopCounter(TIMER_HSR04_INST);
            cnt = DL_TimerG_getTimerCount(TIMER_HSR04_INST);
            dist = cnt*0.017;//
        }
    }


}

//超声波专用定时器，25ms触发，也可以用来计时
void TIMER_HSR04_INST_IRQHandler(void)
{
    if(DL_TimerG_getPendingInterrupt(TIMER_HSR04_INST)==DL_TIMER_IIDX_LOAD)
    {
        overflowFlag = 1;
        // DL_TimerA_clearInterruptStatus(TIMER_HSR04_INST);
    }
}