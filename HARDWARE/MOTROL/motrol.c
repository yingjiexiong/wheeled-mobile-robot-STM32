/*******************************************************************************
 * 文件名  ：sytick.c
 * 描述    ：电机方向，电机转动角度，电机速度控制 
 * 版本    ：1.0
 * 硬件连接: 无
 * 调试方式：J-Link-SWD
 * 备注    ：电机角度需要调试，并不是准确角度值
********************************************************************************/	
//头文件
#include "motrol.h"
#include "pwm.h"
#include "delay.h"
#include "sensor.h"


/*          电机前进速度300（占空比30%）            */
void Motrol_Advance300(void)
{
	setPWM1(1);
	setPWM2(300);
	setPWM3(300);
	setPWM4(1);
}

/*          电机前进速度400（占空比40%）            */
void Motrol_Advance400(void)
{
	setPWM1(1);
	setPWM2(400);
	setPWM3(400);
	setPWM4(1);
}
/*          电机前进速度500（占空比50%）            */
void Motrol_Advance500(void)
{
	setPWM1(1);
	setPWM2(500);
	setPWM3(500);
	setPWM4(1);
}
/*          电机前进速度600（占空比60%）            */
void Motrol_Advance600(void)
{
	setPWM1(1);
	setPWM2(600);
	setPWM3(600);
	setPWM4(1);
}
/*          电机前进速度700（占空比70%）            */
void Motrol_Advance700(void)
{
	setPWM1(1);
	setPWM2(700);
	setPWM3(700);
	setPWM4(1);
}
/*          电机前进速度800（占空比80%）            */
void Motrol_Advance800(void)
{
	setPWM1(1);
	setPWM2(800);
	setPWM3(800);
	setPWM4(1);
}
/*           电机后退速度400（占空比40%)          */
void Motrol_Retreat400(void)
{
	setPWM1(400);
	setPWM2(1);
	setPWM3(1);
	setPWM4(400);
}
/*           电机后退速度500（占空比50%)          */
void Motrol_Retreat500(void)
{
	setPWM1(500);
	setPWM2(1);
	setPWM3(1);
	setPWM4(500);
}
/*           电机后退速度600（占空比60%)          */
void Motrol_Retreat600(void)
{
	setPWM1(600);
	setPWM2(1);
	setPWM3(1);
	setPWM4(600);
}
/*           电机后退速度700（占空比70%)          */
void Motrol_Retreat700(void)
{
	setPWM1(700);
	setPWM2(1);
	setPWM3(1);
	setPWM4(700);
}
/*           电机后退速度800（占空比80%)          */
void Motrol_Retreat800(void)
{
	setPWM1(800);
	setPWM2(1);
	setPWM3(1);
	setPWM4(800);
}
/*           小车上台          */
void Motrol_ImpactArena(void)
{
	setPWM1(500);
	setPWM2(1);
	setPWM3(1);
	setPWM4(500);
}
/*          电机原始左转            */
void Motrol_TurnRight(void)
{
	setPWM1(1);
	setPWM2(700);
	setPWM3(1);
	setPWM4(700);
}
/*           电机原始右转           */
void Motrol_TurnLeft(void)
{
	setPWM1(700);
	setPWM2(1);
	setPWM3(700);
	setPWM4(1);
}
/*           电机左转角度45           */
void Motrol_TurnLeft45_Angle(void)
{
	Motrol_TurnLeft();
	delay_ms(120);
	Motrol_Stop();
}
/*            电机左转角度90          */
void Motrol_TurnLeft90_Angle(void)
{
	Motrol_TurnLeft();
	delay_ms(250);
	Motrol_Stop();
}
/*           电机左转角度180           */
void Motrol_TurnLeft180_Angle(void)
{
	Motrol_TurnLeft();
	delay_ms(500);
	Motrol_Stop();
}
/*            电机右转角度45          */
void Motrol_TurnRight45_Angle(void)
{
	Motrol_TurnRight();
	delay_ms(120);
	Motrol_Stop();
}
/*           电机右转角度90           */
void Motrol_TurnRight90_Angle(void)
{
	Motrol_TurnRight();
	delay_ms(250);
	Motrol_Stop();
}
/*          电机右转角度180            */
void Motrol_TurnRight180_Angle(void)
{
	Motrol_TurnRight();
	delay_ms(465);
	Motrol_Stop();
}
/*                      */
void Motrol_Stop(void)
{
	setPWM1(1);
	setPWM2(1);
	setPWM3(1);
	setPWM4(1);
}


void Prevent_DropArena(void)
{
while(HG1==1&&HG2==1)
	{
		Motrol_Retreat400();
		delay_ms(300);
		Motrol_TurnLeft45_Angle();
		Motrol_Advance400();
	if(HG1==1&&HG2==0)
		{
		Motrol_Retreat400();
		delay_ms(300);
		Motrol_TurnRight45_Angle();
		}
		Motrol_Advance300();
	if(HG2==1&&HG1==0)
		{
		Motrol_Retreat400();
		delay_ms(300);
		Motrol_TurnRight45_Angle();
		}
		delay_ms(200);
		break;
	}
while(HG1==1&&HG2==0)
	{
		Motrol_Retreat400();
		delay_ms(300);
		while(HG3==1||HG4==1)
		{
			Motrol_Advance300();
			delay_ms(400);
			break;
		}
		Motrol_TurnLeft90_Angle();
		break;
	}
while(HG2==1&&HG1==0)
	{
		Motrol_Retreat400();
		delay_ms(300);
		while(HG3==1||HG4==1)
		{
			Motrol_Advance300();
			delay_ms(400);
			break;
		}
		Motrol_TurnRight90_Angle();
		break;
	}
while(HG3==1||HG4==1)
	{
		Motrol_Advance400();
		delay_ms(300);
		break;
	}
	
	
}