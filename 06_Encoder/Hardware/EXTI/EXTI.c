#include "EXTI.h"


int Get_count(void)
{
    return number;
}
void GROUP1_IRQHandler(void)
{
    uint32_t Encoder_A=DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT,GPIO_Encoder_PIN_A_PIN);
    uint32_t Encoder_B=DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PORT,GPIO_Encoder_PIN_B_PIN);
    //1.A相触发
    if(Encoder_A & GPIO_Encoder_PIN_A_PIN)
    {
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
    //2.B相触发
    if(Encoder_B & GPIO_Encoder_PIN_B_PIN)
    {
        // if(DL_GPIO_readPins(GPIO_Encoder_PORT,GPIO_Encoder_PIN_B_PIN))//B相上升沿
        // {
        //    if(DL_GPIO_readPins(GPIO_Encoder_PORT,GPIO_Encoder_PIN_A_PIN))//A相高电平
        //         number++;
        //    else 
        //         number--;
        // }
        // else//B下降沿
        // {
        //     if(DL_GPIO_readPins(GPIO_Encoder_PORT,GPIO_Encoder_PIN_A_PIN))//A相高电平
        //         number--;
        //     else 
        //         number++;
        //  }
    }
}
