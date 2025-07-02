#ifndef __OLED_H
#define __OLED_H			  	 
#include "ti_msp_dl_config.h"
#include "main.h"
// #define  u8 unsigned char 
// #define  u16 unsigned int
// #define  u32 unsigned int
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

#ifndef GPIO_OLED_PIN_SCL_PORT
#define GPIO_OLED_PIN_SCL_PORT GPIO_OLED_PORT 
#endif

#ifndef GPIO_OLED_PIN_SDA_PORT
#define GPIO_OLED_PIN_SDA_PORT GPIO_OLED_PORT 
#endif

//----------------------------------------------------------------------------------
//OLED SSD1306 I2C 时钟SCL
#define		OLED_SCL_Set()			    (DL_GPIO_setPins(GPIO_OLED_PIN_SCL_PORT, GPIO_OLED_PIN_SCL_PIN))
#define		OLED_SCL_Clr()				(DL_GPIO_clearPins(GPIO_OLED_PIN_SCL_PORT, GPIO_OLED_PIN_SCL_PIN))

//----------------------------------------------------------------------------------
//OLED SSD1306 I2C 数据SDA
#define		OLED_SDA_Set()				(DL_GPIO_setPins(GPIO_OLED_PIN_SDA_PORT, GPIO_OLED_PIN_SDA_PIN))
#define		OLED_SDA_Clr()			    (DL_GPIO_clearPins(GPIO_OLED_PIN_SDA_PORT, GPIO_OLED_PIN_SDA_PIN))
				   

//OLED控制用函数
void delay_ms(unsigned long ms);
void OLED_ColorTurn(uint8_t i);
void OLED_DisplayTurn(uint8_t i);
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_Set_Pos(uint8_t x, uint8_t y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);

//显示字符，字符串
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t sizey);
uint32_t oled_pow(uint8_t m,uint8_t n);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t sizey);
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t sizey);

//自定义显示
void OLED_ClearArea(uint8_t X,uint8_t Y, uint8_t Width, uint8_t Height);
void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t no,uint8_t sizey);
void OLED_DrawImage(uint8_t x,uint8_t y,uint8_t Width, uint8_t Height,const uint8_t* Image);
void OLED_MyChinese(uint8_t x,uint8_t y,char* Chinese);
void OLED_Init(void);

#endif  
	 



