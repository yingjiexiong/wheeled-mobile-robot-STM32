#include "pwm.h"
#include "delay.h"






void pwm_Init(void)
{
	GPIO_InitTypeDef         GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef        TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);	//ʹ��TIM2ʱ�ӣ�GPIOAʱ��
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO, ENABLE);//ʹ��GPIOAʱ�Ӻ͸��ù���ʱ��
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1, ENABLE);                           //TIM1��ӳ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14; //TIM1��ͨ��PWM��������˿�PA1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50MHz
	GPIO_Init(GPIOE, &GPIO_InitStructure);
//��ʱ����ʱʱ��T���㹫ʽ��T=(TIM_Period+1)*(TIM_Prescaler+1)
	TIM_TimeBaseStructure.TIM_Period = 999;//�Զ���װ��ֵ��ȡֵ������0x0000~0xFFFF֮��
	TIM_TimeBaseStructure.TIM_Prescaler =71;//Ԥ��Ƶֵ��+1Ϊ��Ƶϵ����ȡֵ������0x0000~0xFFFF֮��		72 000 000/999=1k					 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 				//ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//���ϼ���ģʽ	 
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ 
	TIM_CtrlPWMOutputs(TIM1,ENABLE);                 //                     
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�
	//TIM_OCInitStructure.TIM_Pulse =0; 
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);          //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); //ʹ��TIMx��CCR1�ϵ�Ԥװ�ؼĴ���
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�
	//TIM_OCInitStructure.TIM_Pulse =0;               //���ô�װ�벶��ȽϼĴ���������ֵ,ȡֵ������0x0000~0xFFFF֮��
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);          //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable); //ʹ��TIMx��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�
  //TIM_OCInitStructure.TIM_Pulse =0;               //���ô�װ�벶��ȽϼĴ���������ֵ,ȡֵ������0x0000~0xFFFF֮��
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);          //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable); //ʹ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ���
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             //TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�
	//TIM_OCInitStructure.TIM_Pulse =0; 
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);          //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable); //ʹ��TIMx��CCR4�ϵ�Ԥװ�ؼĴ���
	
	//TIM_Cmd(TIM2, DISABLE);	//��ֹTIM2ʹ��
  TIM_Cmd(TIM1, ENABLE);//ʹ�ܶ�ʱ��	
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