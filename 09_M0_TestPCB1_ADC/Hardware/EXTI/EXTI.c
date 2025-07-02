#include "EXTI.h"

float dist=0;//超声波距离,计次
int overflowFlag=0;//超时不测
int cnt=0;


int Get_Encoder_L_Data(void)//左轮数据
{
    return Encoder_L_Data;
}
int Get_Encoder_R_Data(void)//右轮数据
{
    return Encoder_R_Data;
}


float Get_Juli(void)
{
    return dist;
}


void GROUP1_IRQHandler(void)
{
    /****************************编码器***********************************************************************************************/
    uint32_t Encoder_LA=DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PIN_LA_PORT,GPIO_Encoder_PIN_LA_PIN);
    uint32_t Encoder_LB=DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PIN_LB_PORT,GPIO_Encoder_PIN_LB_PIN);
    uint32_t Encoder_RA=DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PIN_RA_PORT,GPIO_Encoder_PIN_RA_PIN);
    uint32_t Encoder_RB=DL_GPIO_getEnabledInterruptStatus(GPIO_Encoder_PIN_RB_PORT,GPIO_Encoder_PIN_RB_PIN);

    /****************************左轮***************************/
    //1.LA相触发
    if(Encoder_LA & GPIO_Encoder_PIN_LA_PIN)
    {
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_LA_PORT, GPIO_Encoder_PIN_LA_PIN);//清除中断
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_LA_PORT,GPIO_Encoder_PIN_LA_PIN))//LA相上升沿
        {
           if(DL_GPIO_readPins(GPIO_Encoder_PIN_LB_PORT,GPIO_Encoder_PIN_LB_PIN))//LB相高电平
                Encoder_L_Data--;
           else 
                Encoder_L_Data++;
        }
        else//LA下降沿
        {
            if(DL_GPIO_readPins(GPIO_Encoder_PIN_LB_PORT,GPIO_Encoder_PIN_LB_PIN))//LB相高电平
                Encoder_L_Data++;
            else 
                Encoder_L_Data--;
         }
    }
    //2.LB相触发
    if(Encoder_LB & GPIO_Encoder_PIN_LB_PIN)
    {
         DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_LB_PORT, GPIO_Encoder_PIN_LB_PIN);//清除中断
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_LB_PORT,GPIO_Encoder_PIN_LB_PIN))//LB相上升沿
        {
           if(DL_GPIO_readPins(GPIO_Encoder_PIN_LA_PORT,GPIO_Encoder_PIN_LA_PIN))//LA相高电平
                Encoder_L_Data++;
           else 
                Encoder_L_Data--;
        }
        else//LB下降沿
        {
            if(DL_GPIO_readPins(GPIO_Encoder_PIN_LA_PORT,GPIO_Encoder_PIN_LA_PIN))//LA相高电平
                Encoder_L_Data--;
            else 
                Encoder_L_Data++;
         }
    }
    /*****************************右轮******************************/
     //1.RA相触发
    if(Encoder_RA & GPIO_Encoder_PIN_RA_PIN)
    {
        DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_RA_PORT, GPIO_Encoder_PIN_RA_PIN);//清除中断
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_RA_PORT,GPIO_Encoder_PIN_RA_PIN))//RA相上升沿
        {
           if(DL_GPIO_readPins(GPIO_Encoder_PIN_RB_PORT,GPIO_Encoder_PIN_RB_PIN))//RB相高电平
                Encoder_R_Data--;
           else 
                Encoder_R_Data++;
        }
        else//RA下降沿
        {
            if(DL_GPIO_readPins(GPIO_Encoder_PIN_RB_PORT,GPIO_Encoder_PIN_RB_PIN))//RB相高电平
                Encoder_R_Data++;
            else 
                Encoder_R_Data--;
         }
    }
    //2.RB相触发
    if(Encoder_RB & GPIO_Encoder_PIN_RB_PIN)
    {
         DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_RB_PORT, GPIO_Encoder_PIN_RB_PIN);//清除中断
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_RB_PORT,GPIO_Encoder_PIN_RB_PIN))//RB相上升沿
        {
           if(DL_GPIO_readPins(GPIO_Encoder_PIN_RA_PORT,GPIO_Encoder_PIN_RA_PIN))//RA相高电平
                Encoder_R_Data++;
           else 
                Encoder_R_Data--;
        }
        else//RB下降沿
        {
            if(DL_GPIO_readPins(GPIO_Encoder_PIN_RA_PORT,GPIO_Encoder_PIN_RA_PIN))//RA相高电平
                Encoder_R_Data--;
            else 
                Encoder_R_Data++;
         }
    }

    /**************************************超声波******************************************************************************************/
    uint32_t Echo=DL_GPIO_getEnabledInterruptStatus(GPIO_HSR04_PORT,GPIO_HSR04_PIN_Echo_PIN);
    if((Echo & GPIO_HSR04_PIN_Echo_PIN)==GPIO_HSR04_PIN_Echo_PIN)
    {
        DL_GPIO_clearInterruptStatus(GPIO_HSR04_PORT, GPIO_HSR04_PIN_Echo_PIN);
        if(DL_GPIO_readPins(GPIO_HSR04_PORT,GPIO_HSR04_PIN_Echo_PIN))//上升沿
        {
            overflowFlag = 0;
            DL_TimerG_setTimerCount(TIMER_HSR04_INST, 0);
            DL_TimerG_startCounter(TIMER_HSR04_INST);
        }
        else//下降沿
        {
            if(overflowFlag)
            {
                dist = 0;
            }
            DL_TimerG_stopCounter(TIMER_HSR04_INST);
            cnt = DL_TimerG_getTimerCount(TIMER_HSR04_INST);
            dist = cnt*0.017;//
        }
    }

/*****************************MPU6050-INT*****************************************************************************************/
    uint32_t MPU6050_INT=DL_GPIO_getEnabledInterruptStatus(GPIO_MPU6050_PORT,GPIO_MPU6050_PIN_INT_PIN);
    if((MPU6050_INT & GPIO_MPU6050_PIN_INT_PIN)==GPIO_MPU6050_PIN_INT_PIN)
    {
        DL_GPIO_clearInterruptStatus(GPIO_MPU6050_PORT,GPIO_MPU6050_PIN_INT_PIN);
       Read_Quad();
    }

}
//超声波专用定时器，25ms触发，也可以用来计时
void TIMER_HSR04_INST_IRQHandler(void)
{
    if(DL_TimerG_getPendingInterrupt(TIMER_HSR04_INST)==DL_TIMER_IIDX_LOAD)
    {
        overflowFlag = 1;
        // DL_TimerA_clearInterruptStatus(TIMER_HSR04_INST);
    }
}