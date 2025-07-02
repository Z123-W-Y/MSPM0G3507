#ifndef __PID_H
#define __PID_H

#include "main.h"

void PID_Init(PID_Typedef* pid, float kp, float ki, float kd);
float PID_Positional(PID_Typedef* pid, PIDOUT_Typedef* pidout, float reality, float target, float dt);
float PID_Increment(PID_Typedef* pid, PIDOUT_Typedef* pidout, float reality, float target, float dt);
int32_t myabs(int32_t num);
int32_t Limit_int32_t(int32_t original_num, int32_t shangxian, int32_t xiaxian);
float Limit_float(float original_num, float shangxian, float xiaxian);
#endif
/*

*/
