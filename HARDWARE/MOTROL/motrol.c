/*******************************************************************************
 * �ļ���  ��sytick.c
 * ����    ��������򣬵��ת���Ƕȣ�����ٶȿ��� 
 * �汾    ��1.0
 * Ӳ������: ��
 * ���Է�ʽ��J-Link-SWD
 * ��ע    ������Ƕ���Ҫ���ԣ�������׼ȷ�Ƕ�ֵ
********************************************************************************/	
//ͷ�ļ�
#include "motrol.h"
#include "pwm.h"
#include "delay.h"
#include "sensor.h"


/*          ���ǰ���ٶ�300��ռ�ձ�30%��            */
void Motrol_Advance300(void)
{
	setPWM1(1);
	setPWM2(300);
	setPWM3(300);
	setPWM4(1);
}

/*          ���ǰ���ٶ�400��ռ�ձ�40%��            */
void Motrol_Advance400(void)
{
	setPWM1(1);
	setPWM2(400);
	setPWM3(400);
	setPWM4(1);
}
/*          ���ǰ���ٶ�500��ռ�ձ�50%��            */
void Motrol_Advance500(void)
{
	setPWM1(1);
	setPWM2(500);
	setPWM3(500);
	setPWM4(1);
}
/*          ���ǰ���ٶ�600��ռ�ձ�60%��            */
void Motrol_Advance600(void)
{
	setPWM1(1);
	setPWM2(600);
	setPWM3(600);
	setPWM4(1);
}
/*          ���ǰ���ٶ�700��ռ�ձ�70%��            */
void Motrol_Advance700(void)
{
	setPWM1(1);
	setPWM2(700);
	setPWM3(700);
	setPWM4(1);
}
/*          ���ǰ���ٶ�800��ռ�ձ�80%��            */
void Motrol_Advance800(void)
{
	setPWM1(1);
	setPWM2(800);
	setPWM3(800);
	setPWM4(1);
}
/*           ��������ٶ�400��ռ�ձ�40%)          */
void Motrol_Retreat400(void)
{
	setPWM1(400);
	setPWM2(1);
	setPWM3(1);
	setPWM4(400);
}
/*           ��������ٶ�500��ռ�ձ�50%)          */
void Motrol_Retreat500(void)
{
	setPWM1(500);
	setPWM2(1);
	setPWM3(1);
	setPWM4(500);
}
/*           ��������ٶ�600��ռ�ձ�60%)          */
void Motrol_Retreat600(void)
{
	setPWM1(600);
	setPWM2(1);
	setPWM3(1);
	setPWM4(600);
}
/*           ��������ٶ�700��ռ�ձ�70%)          */
void Motrol_Retreat700(void)
{
	setPWM1(700);
	setPWM2(1);
	setPWM3(1);
	setPWM4(700);
}
/*           ��������ٶ�800��ռ�ձ�80%)          */
void Motrol_Retreat800(void)
{
	setPWM1(800);
	setPWM2(1);
	setPWM3(1);
	setPWM4(800);
}
/*           С����̨          */
void Motrol_ImpactArena(void)
{
	setPWM1(500);
	setPWM2(1);
	setPWM3(1);
	setPWM4(500);
}
/*          ���ԭʼ��ת            */
void Motrol_TurnRight(void)
{
	setPWM1(1);
	setPWM2(700);
	setPWM3(1);
	setPWM4(700);
}
/*           ���ԭʼ��ת           */
void Motrol_TurnLeft(void)
{
	setPWM1(700);
	setPWM2(1);
	setPWM3(700);
	setPWM4(1);
}
/*           �����ת�Ƕ�45           */
void Motrol_TurnLeft45_Angle(void)
{
	Motrol_TurnLeft();
	delay_ms(120);
	Motrol_Stop();
}
/*            �����ת�Ƕ�90          */
void Motrol_TurnLeft90_Angle(void)
{
	Motrol_TurnLeft();
	delay_ms(250);
	Motrol_Stop();
}
/*           �����ת�Ƕ�180           */
void Motrol_TurnLeft180_Angle(void)
{
	Motrol_TurnLeft();
	delay_ms(500);
	Motrol_Stop();
}
/*            �����ת�Ƕ�45          */
void Motrol_TurnRight45_Angle(void)
{
	Motrol_TurnRight();
	delay_ms(120);
	Motrol_Stop();
}
/*           �����ת�Ƕ�90           */
void Motrol_TurnRight90_Angle(void)
{
	Motrol_TurnRight();
	delay_ms(250);
	Motrol_Stop();
}
/*          �����ת�Ƕ�180            */
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