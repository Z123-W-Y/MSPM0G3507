#include "PID.h"

void PID_Init(PID_Typedef *pid, float kp, float ki, float kd)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
}

/*
    经典位置式 PID
        参数1：PID参数
        参数2：PID计算参数
        参数3：实际值
        参数4：目标值
        参数5：PID运行周期
 */
float PID_Positional(PID_Typedef *pid, PIDOUT_Typedef *pidout, float reality, float target, float dt)
{
    // 计算误差
    pidout->error = target - reality;
    // 当误差值 小于 输入死区，就不进行PID计算，输出值直接为0
    if (myabs(pidout->error) <= pid->deadzone_in)
    {
        // pidout->integral = 0;
        // pidout->output = 0;
        // pidout->lastlast_error = pidout->last_error;
        // pidout->last_error = pidout->error;
        return pidout->output;
    }
    // 正常计算PID
    else
    {
        // 计算积分
        pidout->integral += pidout->error * dt;
        // 积分限幅
        pidout->integral = Limit_float(pidout->integral, (float)(pid->limit_integral), -(float)(pid->limit_integral));
        // 计算微分
        float derivative = (pidout->error - pidout->last_error) / dt;

        // PID计算
        pidout->CalculationResults = pid->kp * pidout->error + pid->ki * pidout->integral + pid->kd * derivative;

        // 更新上一次误差值
        pidout->lastlast_error = pidout->last_error;
        pidout->last_error = pidout->error;

        // 计算值赋给输出值
        pidout->output = pidout->CalculationResults;

        // 返回PID的输出值
        return pidout->output;
    }
}

// 增量式PID
float PID_Increment(PID_Typedef *pid, PIDOUT_Typedef *pidout, float reality, float target, float dt)
{
    // 计算误差
    pidout->error = target - reality;

    if (myabs(pidout->error) <= pid->deadzone_in)
    {
        pidout->integral = 0;
        return pidout->output;
    }
    else
    {
        // 计算积分
        pidout->integral += pidout->error * dt;
        // 积分限幅
        pidout->integral = Limit_float(pidout->integral, (float)(pid->limit_integral), -(float)(pid->limit_integral));

        // PID计算
        pidout->CalculationResults = pid->kp * (pidout->error - pidout->last_error) + pid->ki * pidout->integral + pid->kd * ((pidout->error - pidout->last_error * 2 + pidout->lastlast_error) / dt);

        pidout->lastlast_error = pidout->last_error;
        pidout->last_error = pidout->error;

        // 需要限幅之后再累加
        pidout->output = Limit_float(pidout->output, pid->limit_output_max, pid->limit_output_min);
        pidout->output += pidout->CalculationResults;

        // 返回PID的输出值
        return pidout->output;
    }
}


int32_t myabs(int32_t num)
{
    if (num < 0)
    {
        num = -(num);
    }
    return num;
}

/* 限幅函数 */
int32_t Limit_int32_t(int32_t original_num, int32_t shangxian, int32_t xiaxian)
{
	if (original_num > shangxian)
	{
		return shangxian;
	}
	else if (original_num < xiaxian)
	{
		return xiaxian;
	}
	return original_num;
}

//分上限和下限
float Limit_float(float original_num, float shangxian, float xiaxian)
{
	if (original_num > shangxian)
	{
		return shangxian;
	}
	if (original_num < xiaxian)
	{
		return xiaxian;
	}
	return original_num;
}
