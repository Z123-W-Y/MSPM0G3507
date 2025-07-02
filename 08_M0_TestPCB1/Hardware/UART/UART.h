#ifndef __UART_H
#define __UART_H

#include "main.h"
void UART0_SendByte(char ch);
void UART0_SendString(char* str);
unsigned char UART0_GetFlag(void);
extern unsigned char UART0_RxPacket[100]; // 定义接收数据包数组
#endif
