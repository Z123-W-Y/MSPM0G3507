#include "Delay.h"
#include "ti_msp_dl_config.h"

// 搭配滴答定时器实现的精确ms延时
void Delay_us(unsigned int us)
{
    while (us--)
        delay_cycles(CPUCLK_FREQ / 1000000);
}
void Delay_ms(unsigned int ms)
{
    while (ms--)
        Delay_us(1000);
}

void Delay_s(unsigned int s)
{
    while (s--)
        Delay_ms(1000);
}
