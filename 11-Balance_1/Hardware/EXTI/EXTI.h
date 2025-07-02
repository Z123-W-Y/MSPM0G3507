#ifndef __EXTI_H
#define __EXTI_H

#include "main.h"

int Get_Encoder_L_Data(void);
int Get_Encoder_R_Data(void);
float Get_Juli(void);



int Erect_PD(float measure, float Gyro);//直立环PD
int Speed_PI(int Speed_measure);//速度环PI
int Turn(int gyro_Z);//转向环

#endif