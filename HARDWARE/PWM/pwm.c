#include "pwm.h"
#include "delay.h"






void pwm_Init(void)
{
	GPIO_InitTypeDef         GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef        TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);	//使能TIM2时钟，GPIOA时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO, ENABLE);//使能GPIOA时钟和复用功能时钟
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1, ENABLE);                           //TIM1重映射
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14; //TIM1二通道PWM波形输出端口PA1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
	GPIO_Init(GPIOE, &GPIO_InitStructure);
//定时器定时时间T计算公式：T=(TIM_Period+1)*(TIM_Prescaler+1)
	TIM_TimeBaseStructure.TIM_Period = 999;//自动重装载值，取值必须在0x0000~0xFFFF之间
	TIM_TimeBaseStructure.TIM_Prescaler =71;//预分频值，+1为分频系数，取值必须在0x0000~0xFFFF之间		72 000 000/999=1k					 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 				//时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//向上计数模式	 
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位 
	TIM_CtrlPWMOutputs(TIM1,ENABLE);                 //                     
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //输出极性:TIM输出比较极性高
	//TIM_OCInitStructure.TIM_Pulse =0; 
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);          //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); //使能TIMx在CCR1上的预装载寄存器
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //输出极性:TIM输出比较极性高
	//TIM_OCInitStructure.TIM_Pulse =0;               //设置待装入捕获比较寄存器的脉冲值,取值必须在0x0000~0xFFFF之间
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);          //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable); //使能TIMx在CCR2上的预装载寄存器
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //输出极性:TIM输出比较极性高
  //TIM_OCInitStructure.TIM_Pulse =0;               //设置待装入捕获比较寄存器的脉冲值,取值必须在0x0000~0xFFFF之间
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);          //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable); //使能TIMx在CCR3上的预装载寄存器
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //输出极性:TIM输出比较极性高
	//TIM_OCInitStructure.TIM_Pulse =0; 
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);          //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable); //使能TIMx在CCR4上的预装载寄存器
	
	//TIM_Cmd(TIM2, DISABLE);	//禁止TIM2使能
  TIM_Cmd(TIM1, ENABLE);//使能定时器	
	TIM_ARRPreloadConfig(TIM1,ENABLE);   // 
	
	
}

void setPWM1(unsigned short pwm1)
{
	TIM1->CCR1=pwm1;
}


void setPWM2(unsigned short pwm2)
{
	TIM1->CCR2=pwm2;
}

void setPWM3(unsigned short pwm3)
{
	TIM1->CCR3=pwm3;
}

void setPWM4(unsigned short pwm4)
{
	TIM1->CCR4=pwm4;
}