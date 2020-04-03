#ifndef __PWM_H
#define __PWM_H
#include "stm32f10x.h"
#include "stm32f10x_tim.h"
void pwm_Init(void);
//void setPWM(unsigned short pwm1, unsigned short pwm2,unsigned short pwm3,unsigned short pwm4) ;
void setPWM1(unsigned short pwm1);
void setPWM2(unsigned short pwm2);
void setPWM3(unsigned short pwm3);
void setPWM4(unsigned short pwm4);

#endif