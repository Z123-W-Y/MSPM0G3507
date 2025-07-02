#include "HSR04.h"

void Trig_HL(void)
{
    DL_GPIO_setPins(GPIO_HSR04_PORT, GPIO_HSR04_PIN_Trig_PIN);  
	Delay_us(10);
	DL_GPIO_clearPins(GPIO_HSR04_PORT, GPIO_HSR04_PIN_Trig_PIN);
}


