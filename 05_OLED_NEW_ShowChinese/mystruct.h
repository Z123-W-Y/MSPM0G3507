#ifndef __MYSTRUCT_H
#define __MYSTRUCT_H

#include "main.h"


/* 接收到修改的PID参数 */
typedef struct
{
    float setkp;             // 设置Kp
    float setki;             // 设置Ki
    float setkd;             // 设置Kd
    float setdt;             // 设置dt
    uint32_t setinputlimit;  // 输入限幅
    uint32_t setjifenlimit;  // 积分限幅
    uint32_t setoutputlimit; // 输出限幅
    float target;            // 目标值
} RecData_PID_TypeDef;

/* PID的各种参数 */
typedef struct
{
    float kp;                  // 参数Kp
    float ki;                  // 参数Ki
    float kd;                  // 参数Kd
    uint32_t limit_integral;   // 积分限幅值
    uint32_t limit_output_max; // 输出限幅值
    uint32_t limit_output_min; // 输入限幅值
    float deadzone_in;         // 输入死区
    float deadzone_out;        // 输出死区
} PID_Typedef;

/* PID的各种计算值 */
typedef struct
{
    float error;              // 误差
    float last_error;         // 上一次的误差
    float lastlast_error;     // 上上次的误差
    float integral;           // 积分值
    float CalculationResults; // 计算结果
    float output;             // 输出值
} PIDOUT_Typedef;

typedef struct
{
    float KPL; // L
    float KIL;
    float KDL;

    float KPR; // R
    float KIR;
    float KDR;
} VOFA_Typedef;

typedef struct
{
    int Count_L;
    int Count_R;
    int All_Count;
}Motor_Typedef;

typedef enum
{
    STOP=0,
    FRONT,
    BACK,
    LEFT,
    RIGHT,
    STOP_ZITAI,
    QUICK
}DIR_Typedef;//上位机方向控制

extern char str[72];
extern uint8_t oled_buffer[72];
extern int Encoder_L_Data;//左电机脉冲数
extern int Encoder_R_Data;//右电机脉冲数
//结构体大写
extern PID_Typedef PID_L;
extern PID_Typedef PID_R;
extern PIDOUT_Typedef PIDOUT_L;
extern PIDOUT_Typedef PIDOUT_R;
extern VOFA_Typedef VOFA;
extern Motor_Typedef MOTOR;
extern DIR_Typedef DIR;

#endif