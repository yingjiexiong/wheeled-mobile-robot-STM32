#ifndef  __SENSOR_H
#define  __SENSOR_H

#include "stm32f10x.h"

#define HG1   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0)  //right advance
#define HG2   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_1)  //left  advance
#define HG3   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)
#define HG4   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)
#define GD1   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)
#define GD2   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)
#define GD3   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_7)
#define GD4   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_8)
void CGQ_Config(void);
#endif