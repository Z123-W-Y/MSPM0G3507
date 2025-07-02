#ifndef __PWM_H
#define __PWM_H

#include "main.h"
void PWM_Test(void);
void PWM_Duty(uint8_t channel,uint32_t duty);
void Set_Freq(uint8_t channel,uint32_t freq);
#endif
