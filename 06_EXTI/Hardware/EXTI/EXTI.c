#include "EXTI.h"

volatile int number = 0;
int Get_count(void)
{
    return number;
}
void GROUP1_IRQHandler(void)
{
    //读取Group1的中断寄存器并清除中断标志位
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
        //检查是否是KEY的GPIOB端口中断，注意是INT_IIDX，不是PIN_22_IIDX
        case GPIO_ENCODE_INT_IIDX:
            //如果按键按下变为高电平
            if( DL_GPIO_readPins(GPIO_ENCODE_PORT, GPIO_ENCODE_PIN_16_PIN) > 0 )
            {
                number ++;
                if(number >= 2000)
                {
                    //设置LED引脚状态翻转
                    DL_GPIO_togglePins(GPIO_LED_PORT, GPIO_LED_PIN_LED_1_PIN);  
                    number = 0;
                }

            }
        break;
    }

}
