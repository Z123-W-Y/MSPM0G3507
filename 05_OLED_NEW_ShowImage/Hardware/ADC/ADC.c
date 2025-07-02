#include "ADC.h"

volatile int ADC_Val;
volatile float real_val;
int Get_ADC_Val(void)
{
    return ADC_Val;
}

void ADC12_0_INST_IRQHandler(void)
{
    if(DL_ADC12_getPendingInterrupt(ADC12_0_INST)==DL_ADC12_IIDX_MEM0_RESULT_LOADED)//会自动清除标志位
    {
        ADC_Val=DL_ADC12_getMemResult(ADC12_0_INST,DL_ADC12_MEM_IDX_0);//读取结果
        real_val=(ADC_Val/4096.0f)*3.3f/0.09f;
        DL_ADC12_enableConversions(ADC12_0_INST);//使能
    }
}
