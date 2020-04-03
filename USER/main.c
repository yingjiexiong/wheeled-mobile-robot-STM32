#include "adc.h"
#include "dma.h"
#include "motrol.h"
#include "pwm.h"
#include "sensor.h"
#include "delay.h"
#include "usart.h"

#define ADC1_DR_Address    ((u32)0x40012400+0x4c)
u16 value[10][10];
long int value_mean[10];
void ADC_temp(void);
void ADC_meanvalue(void);
void ADC_meanvaluetest(void);

int main(void)
{
	delay_init();
  delay_ms(1000);	            //ÑÓÊ±º¯Êý³õÊ¼»¯	
	NVIC_Configuration(); 	    //ÉèÖÃNVICÖÐ¶Ï·Ö×é2:2Î»ÇÀÕ¼ÓÅÏÈ¼¶£¬2Î»ÏìÓ
  MYDMA_Config(DMA1_Channel1,ADC1_DR_Address,(u32)value,100);  //³õÊ¼»¯DMA
  Adc_Init();
	delay_ms(100);
	uart_init(115200);	//
	CGQ_Config();
	pwm_Init();	
	ADC_meanvaluetest();
	while(1)
	{ 	
		Motrol_ImpactArena();
		delay_ms(800);
		delay_ms(800);
		Motrol_TurnLeft90_Angle();
		while(1)
		{
		Prevent_DropArena();
			if(HG1==0&&HG2==0&&HG3==0&&HG4==0)
			{
        ADC_meanvaluetest(); 
				Motrol_Advance300();
				if( (value_mean[0]>900||value_mean[1]>900)&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
         	{ 
						Motrol_Advance400();
	        }
	      else if(value_mean[2]>1300&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
	        {
		       Motrol_TurnRight45_Angle();
	        }
	      else if(value_mean[3]>1300&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
	        {
	          	Motrol_TurnRight45_Angle();
	        }
	
	      else if(value_mean[4]>1300&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
	        {
	         	Motrol_TurnRight45_Angle();
	        }
	      else if((value_mean[5]>1300||value_mean[6]>1300)&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
	        {
	        	Motrol_TurnRight180_Angle();
	        }
	      else if(value_mean[7]>1300&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
	        {
	         	Motrol_TurnLeft90_Angle();
	        }
	      else if(value_mean[8]>1300&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
	        {
	         	Motrol_TurnLeft45_Angle();
	        }
          	else if(value_mean[9]>1400&&HG1==0&&HG2==0&&HG3==0&&HG4==0)
	        {
	         	Motrol_TurnLeft45_Angle();
	        }
  
   }
  }
}
}

void ADC_meanvaluetest(void)
{
 
	
	value_mean[0]=(value[0][0]+value[1][0]+value[2][0]+value[3][0]+value[4][0]+value[5][0]+value[6][0]+value[7][0]+value[8][0]+value[9][0])/10;
	value_mean[1]=(value[0][1]+value[1][1]+value[2][1]+value[3][1]+value[4][1]+value[5][1]+value[6][1]+value[7][1]+value[8][1]+value[9][1])/10;
	value_mean[2]=(value[0][2]+value[1][2]+value[2][2]+value[3][2]+value[4][2]+value[5][2]+value[6][2]+value[7][2]+value[8][2]+value[9][2])/10;
	value_mean[3]=(value[0][3]+value[1][3]+value[2][3]+value[3][3]+value[4][3]+value[5][3]+value[6][3]+value[7][3]+value[8][3]+value[9][3])/10;
	value_mean[4]=(value[0][4]+value[1][4]+value[2][4]+value[3][4]+value[4][4]+value[5][4]+value[6][4]+value[7][4]+value[8][4]+value[9][4])/10;
	value_mean[5]=(value[0][5]+value[1][5]+value[2][5]+value[3][5]+value[4][5]+value[5][5]+value[6][5]+value[7][5]+value[8][5]+value[9][5])/10;
	value_mean[6]=(value[0][6]+value[1][6]+value[2][6]+value[3][6]+value[4][6]+value[5][6]+value[6][6]+value[7][6]+value[8][6]+value[9][6])/10;
	value_mean[7]=(value[0][7]+value[1][7]+value[2][7]+value[3][7]+value[4][7]+value[5][7]+value[6][7]+value[7][7]+value[8][7]+value[9][7])/10;
	value_mean[8]=(value[0][8]+value[1][8]+value[2][8]+value[3][8]+value[4][8]+value[5][8]+value[6][8]+value[7][8]+value[8][8]+value[9][8])/10;
	value_mean[9]=(value[0][9]+value[1][9]+value[2][9]+value[3][9]+value[4][9]+value[5][9]+value[6][9]+value[7][9]+value[8][9]+value[9][9])/10;

	}