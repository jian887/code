#include "led.h"
#include "stm32f10x.h"

void LED_Init(void){
	
	GPIO_InitTypeDef GPIO_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOD,&GPIO_Initstruct);
	
	GPIO_ResetBits(GPIOD,GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
	

}
