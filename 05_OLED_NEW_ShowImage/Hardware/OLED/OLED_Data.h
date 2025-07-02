#ifndef __OLED_DATA_H
#define __OLED_DATA_H

#include "ti_msp_dl_config.h"
#define OLED_CHN_CHAR_WIDTH			3		//UTF-8编码格式给3，GB2312编码格式给2

/*字模基本单元*/
typedef struct 
{
	
	char Index[OLED_CHN_CHAR_WIDTH + 1];	//汉字索引
	uint8_t Data[32];				//字模数据
}Chinese_Typedef;

extern const unsigned char asc2_0806[][6];//8x6
extern const unsigned char asc2_1608[][16];//16x8
extern const Chinese_Typedef OLED_16x16[];//自定义中文字模
extern uint8_t BMP1[];//图片
extern const uint8_t ke[];
#endif