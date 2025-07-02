#include "Key.h"
//上拉电阻
void LED_TIG(void)
{
	DL_GPIO_setPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_1_PIN);  
	Delay_ms(1000);
	DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_1_PIN);
}

int KeyScan(void)
{
	int key=0;
  if(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_S1_PIN)==0)
	{
		Delay_ms(7);
		key=1;
		while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY_S1_PIN)==0);
	}
	return key;
}