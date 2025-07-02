#include "EXTI.h"
/**********************平衡车控制*****************/
float Med_Angle = -10.5;						//机械中值
float Erect_Kp = -330,		//直立环Kp
	  Erect_Kd = -2.2;		//直立环Kd

float Speed_Kp = 110,		//速度环Kp
	  Speed_Ki = 0.55;			//速度环Ki

float Turn_Kp = 40,//转向环kp
	  Turn_Kd = 0;//转向环kd

int Erect_out,//直立环输出
    Speed_out,//速度环输出
    Turn_out;		//输出变量

extern float Med_Angle;						//机械中值
int measure;								//编码器速度测量值
int motor1, motor2;
/*****************************************************/


float dist=0;//超声波距离,计次
int overflowFlag=0;//超时不测
int cnt=0;//获取超声波计次


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

    /*****************************MPU6050-INT*****************************************************************************************/
    uint32_t MPU6050_INT=DL_GPIO_getEnabledInterruptStatus(GPIO_MPU6050_PORT,GPIO_MPU6050_PIN_INT_PIN);
    if((MPU6050_INT & GPIO_MPU6050_PIN_INT_PIN)==GPIO_MPU6050_PIN_INT_PIN)
    {
        int pwm_out;
        DL_GPIO_clearInterruptStatus(GPIO_MPU6050_PORT,GPIO_MPU6050_PIN_INT_PIN);
        Read_Quad();//读取MPU6050角速度，加速度，姿态角
        MOTOR.All_Count=MOTOR.Count_L+MOTOR.Count_R;//编码器速度测量值
        Erect_out=Erect_PD(pitch, (float)gyro[1]);
        Speed_out=Speed_PI(MOTOR.All_Count);
        Turn_out=Turn((float)gyro[2]);

        pwm_out=Erect_out+Speed_out;
        motor1=pwm_out-Turn_out;
        motor2=pwm_out+Turn_out;
        Limit(&motor1, &motor2);
        if(!Turn_Off(pitch))
        {
            PWM_Duty(0,motor1);
            PWM_Duty(1,motor2);
        }
    }


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
                Encoder_L_Data++;
           else 
                Encoder_L_Data--;
        }
        else//LA下降沿
        {
            if(DL_GPIO_readPins(GPIO_Encoder_PIN_LB_PORT,GPIO_Encoder_PIN_LB_PIN))//LB相高电平
                Encoder_L_Data--;
            else 
                Encoder_L_Data++;
         }
    }
    //2.LB相触发
    if(Encoder_LB & GPIO_Encoder_PIN_LB_PIN)
    {
         DL_GPIO_clearInterruptStatus(GPIO_Encoder_PIN_LB_PORT, GPIO_Encoder_PIN_LB_PIN);//清除中断
        if(DL_GPIO_readPins(GPIO_Encoder_PIN_LB_PORT,GPIO_Encoder_PIN_LB_PIN))//LB相上升沿
        {
           if(DL_GPIO_readPins(GPIO_Encoder_PIN_LA_PORT,GPIO_Encoder_PIN_LA_PIN))//LA相高电平
                Encoder_L_Data--;
           else 
                Encoder_L_Data++;
        }
        else//LB下降沿
        {
            if(DL_GPIO_readPins(GPIO_Encoder_PIN_LA_PORT,GPIO_Encoder_PIN_LA_PIN))//LA相高电平
                Encoder_L_Data++;
            else 
                Encoder_L_Data--;
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
            DL_TimerG_startCounter(TIMER_HSR04_INST);//开启计时
        }
        else//下降沿
        {
            if(overflowFlag)
            {
                dist = 0;
            }
            DL_TimerG_stopCounter(TIMER_HSR04_INST);//停止计时
            cnt = DL_TimerG_getTimerCount(TIMER_HSR04_INST);
            dist = cnt*0.017;//1us记一次
        }
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

//直立环PD
/*
    俯仰角
    measure:当前测量的角度
    Gyro：当前测量的角速度
*/
int Erect_PD(float measure, float Gyro)
{
	int PWM_out;
	
	PWM_out = Erect_Kp*(measure - Med_Angle) + Erect_Kd*Gyro;
	return PWM_out;
}

//速度环PI
//平衡车的目标是保持速度保持一个静止的状态并直立
int Speed_PI(int Speed_measure)
{
	static int Encoder_err,//误差速度
            Encoder_err_low,//低通滤波后的误差速度
            Encoder_err_low_last,//上一次滤波后的误差
            Encoder_sum,//误差积分
            Movement;
	static int PWM_out;
	static float Target_Velocity = 200;
	
    switch (DIR) 
    {
        case FRONT: Movement = Target_Velocity / 2;     break;
        case BACK:  Movement = -Target_Velocity / 2;    break;
        case STOP:  Movement = 0;                       break;
        case QUICK: Movement = Target_Velocity;         break;
        default:    Movement = 0;                       break;
    }
	Encoder_err = 0 - Speed_measure;//目标速度-实际速度
	Encoder_err_low = 0.3 * Encoder_err + 0.7 * Encoder_err_low_last;//低通滤波
	Encoder_err_low_last = Encoder_err_low;//递归滤波
	Encoder_sum += Encoder_err_low;//误差积分
	Encoder_sum = Encoder_sum + Movement;//外部干预
    
	if(Encoder_sum > 10000) Encoder_sum = 10000;//积分限幅
	if(Encoder_sum < -10000) Encoder_sum = -10000;
	
	PWM_out = Speed_Kp*Encoder_err + Speed_Ki*Encoder_sum;
	if(Turn_Off(pitch)) Encoder_sum = 0;
	return PWM_out;
}

//转向环
int Turn(int gyro_Z)
{
	int PWM_out;
	static float Turn_Target, Turn_Amplitude=40;
	float Kp = Turn_Kp,Kd;			
	
    switch (DIR)
    {
        case LEFT:Turn_Target = -Turn_Amplitude/2;break;
        case RIGHT:Turn_Target = Turn_Amplitude/2;break;
        case STOP_ZITAI:Turn_Target = 0;break;
        default:Turn_Target = 0;break;
    }

	if(DIR==FRONT || DIR==BACK)  Kd = Turn_Kd;        
	else Kd = 0;   
	
	PWM_out = Turn_Target * Kp + gyro_Z * Kd;
	
	return PWM_out;
}





