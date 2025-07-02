#ifndef __UART_H
#define __UART_H

#include "main.h"
void UART0_SendByte(char ch);
void UART0_SendString(char* str);
unsigned char UART0_GetFlag(void);
#endif
