#include "Key.h"
//上拉电阻
void LED_TIG(void)
{
	DL_GPIO_setPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_1_PIN);  
	Delay_ms(500);
	DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_1_PIN);
}

void BUZZ_TIG(void)
{
	DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_BUZZ_PIN_BUZZ_1_PIN);
	Delay_ms(500);
	DL_GPIO_setPins(GPIO_BUZZ_PORT, GPIO_BUZZ_PIN_BUZZ_1_PIN);  

}

int KeyScan(void)
{
	int key=0;
    if(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_S1_PIN)==0)//s1
	{
		Delay_ms(7);
		key=1;
		while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_S1_PIN)==0);
	}
    else if(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW2_PIN)==0)//sw2
    {
        Delay_ms(7);
		key=2;
		while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW2_PIN)==0);
    }
    else if(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW3_PIN)==0)//sw3
    {
        Delay_ms(7);
		key=3;
		while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW3_PIN)==0);
    }
    else if(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW4_PIN)==0)//sw4
    {
        Delay_ms(7);
		key=4;
		while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW4_PIN)==0);
    }
    else if(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW5_PIN)==0)//sw5
    {
        Delay_ms(7);
		key=5;
		while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_SW5_PIN)==0);
    }
	return key;
}