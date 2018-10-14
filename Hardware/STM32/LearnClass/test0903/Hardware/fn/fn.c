#include "fn.h"
#include "stm32f10x.h"

void FN_Init(void){
	
	GPIO_InitTypeDef GPIO_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_Initstruct.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOC,&GPIO_Initstruct);
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_8|GPIO_Pin_9);
	

}
