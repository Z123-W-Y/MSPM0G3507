/***************************************************
USART：
	UART0_TX(PA00/PA28/PB00/PA10)
	UART0_RX(PA01/PA31/PB01/PA11)
	
	UART1_TX(PA17/PB04/PA08/PB06)
	UART1_RX(PA18/PB05/PA09/PB07)
	
	UART2_TX(PB15/PB17/PA21/PA23)
	UART2_Rx(PB16/PB18/PA22/PA24)
	
	UART3_TX(PA14/PA26/PB02/PB12)
	UART3_RX(PB13/PA13/PA25/PB03)
*****************************************************/
#include "UART.h"

volatile unsigned char uart_data = 0;
unsigned char UART0_TxPacket[100]; // 定义发送数据包数组，数据包格式：FF 01 02 03 04 FE
unsigned char UART0_RxPacket[100]; // 定义接收数据包数组
unsigned char UART0_RxFlag;		  // 定义接收数据包标志位
//UART0
//串口发送单个字符
void UART0_SendByte(char ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_0_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_0_INST, ch);
	//		DL_UART_transmitDataBlocking();
}

//串口发送字符串
void UART0_SendString(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        UART0_SendByte(*str++);
    }
}
unsigned char UART0_GetFlag(void)
{
	if(UART0_RxFlag==1)
	{
		UART0_RxFlag=0;
		return 1;
	}
	return 0;
}

//串口的中断服务函数-优化版
void UART0_IRQHandler(void)
{
	static unsigned char RxState = 0;
	static unsigned char pRxPacket = 0;	
	if( DL_UART_getPendingInterrupt(UART0)==DL_UART_IIDX_RX )
	{
		unsigned char RxData= DL_UART_Main_receiveData(UART0);
		//将保存的数据再发送出去
		if(RxState==0)
		{
			if(RxData==0xff)
			{
				RxState=1;
				pRxPacket=0;
			}
		}
		else if(RxState==1)
		{
			if(RxData!=0xfe)
			{
				UART0_RxPacket[pRxPacket++]=RxData;
			}
			else if(RxData==0xfe)
			{
				RxState=0;
				UART0_RxFlag=1;
			}
		}
		DL_UART_clearInterruptStatus(UART0,DL_UART_INTERRUPT_RX);//清楚接收中断
	}
}


////串口的中断服务函数
//void UART0_IRQHandler(void)
//{
//    //如果产生了串口中断
//    switch( DL_UART_getPendingInterrupt(UART0) )
//    {
//        case DL_UART_IIDX_RX://如果是接收中断
//            //接发送过来的数据保存在变量中
//            uart_data = DL_UART_Main_receiveData(UART0);
//            //将保存的数据再发送出去
//            uart0_send_char(uart_data);
//            break;
//        default://其他的串口中断
//            break;
//    }
//}


////串口的中断服务函数-优化版
//void UART0_IRQHandler(void)
//{
//	static unsigned char RxState = 0;
//	static unsigned char pRxPacket = 0;	
//	if( DL_UART_getPendingInterrupt(UART0)==DL_UART_IIDX_RX )
//	{
//		unsigned char RxData= DL_UART_Main_receiveData(UART0);
//		//将保存的数据再发送出去
//		if(RxState==0)
//		{
//			if(RxData==0xff)
//			{
//				RxState=1;
//				pRxPacket=0;
//			}
//		}
//		else if(RxState==1)
//		{
//			if(RxData!=0xfe)
//			{
//				UART0_RxPacket[pRxPacket++]=RxData;
//			}
//			else if(RxData==0xfe)
//			{
//				RxState=0;
//				UART0_RxFlag=1;
//			}
//		}
//		DL_UART_clearInterruptStatus(UART0,DL_UART_INTERRUPT_RX);//清楚接收中断
//	}
//}


////串口的中断服务函数-防包头版0xc0
//void USART3_IRQHandler(void)
//{
//	static unsigned char RxState = 0;							 
//	static unsigned char pRxPacket = 0;						 
//	static unsigned char hand_flag=0;//转义字符标志位
//	if( DL_UART_getPendingInterrupt(UART0)==DL_UART_IIDX_RX )
//	{

//		unsigned char RxData= DL_UART_Main_receiveData(UART0);

//		/*使用状态机的思路，依次处理数据包的不同部分*/

//		/*当前状态为0，接收数据包包头*/
//		if (RxState == 0)
//		{
//			if (RxData == 0xc0) // 如果数据确实是包头
//			{
//				RxState = 1;   // 置下一个状态
//				pRxPacket = 0; // 数据包的位置归零
//			}
//		}
//		/*当前状态为1，接收数据包数据*/
//		else if (RxState == 1)
//		{
//			if (RxData != 0xc0)
//			{
//				if (hand_flag == 1)  // 上一个字节是转义字符（0xDD）
//        {
//            hand_flag = 0;   // 重置标志
//            if (RxData == 0xdb)
//            {
//                UART0_RxPacket[pRxPacket++] = 0xc0;  // 转义为 0xc0
//            }
//            else if (RxData == 0xdc)
//            {
//                UART0_RxPacket[pRxPacket++] = 0xdd;  // 转义为 0xdd
//            }
//            // 其他情况可视为协议错误，这里选择忽略
//        }
//        else if (RxData ==0xdd)  // 遇到转义前缀
//        {
//            hand_flag = 1;        // 标记下一个字节需要转义
//        }
//        else  // 普通数据
//        {
//            UART0_RxPacket[pRxPacket++] = RxData;  // 存入数据包
//        }
//			}
//			else if (RxData == 0xc0)
//			{
//				RxState = 0;	   // 状态归0
//				UART0_RxFlag = 1; // 接收数据包标志位置1，成功接收一个数据包
//			}
//		}
//		DL_UART_clearInterruptStatus(UART0,DL_UART_INTERRUPT_RX);//清楚接收中断
//	}
//}