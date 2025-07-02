#include "PWM.h"
void PWM_Test(void)
{
	for(int i=0;i<999;i++)
	{
		DL_TimerG_setCaptureCompareValue(PWM_0_INST,i,DL_TIMER_CC_0_INDEX);//定时器，占空比，定时器通道
        DL_TimerG_setCaptureCompareValue(PWM_0_INST,i,DL_TIMER_CC_1_INDEX);//定时器，占空比，定时器通道
		Delay_ms(1);
	}
		for(int i=999;i>0;i--)
	{
		DL_TimerG_setCaptureCompareValue(PWM_0_INST,i,DL_TIMER_CC_0_INDEX);
        DL_TimerG_setCaptureCompareValue(PWM_0_INST,i,DL_TIMER_CC_1_INDEX);//定时器，占空比，定时器通道
		Delay_ms(1);
	}
}


//PWM占空比1~1000，高电平在周期占比
void PWM_Duty(uint8_t channel,uint32_t duty)
{
    if(channel==0)
    {
        DL_TimerG_setCaptureCompareValue(PWM_0_INST,duty,DL_TIMER_CC_0_INDEX);
    }
    else if(channel==1)
    {
        DL_TimerG_setCaptureCompareValue(PWM_0_INST,duty,DL_TIMER_CC_1_INDEX);
    }
}
//设置频率，即信号周期的总时间
void Set_Freq(uint8_t channel,uint32_t freq)
{
    DL_TimerG_setLoadValue(PWM_0_INST,PWM_0_INST_CLK_FREQ/freq);
}