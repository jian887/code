#include "key.h"
#include "stm32f10x.h"

void KEY_Init(void){
	GPIO_InitTypeDef G_GPIO_InitStructure;
	//GPIO_InitTypeDef A_GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOA,ENABLE);
	
	G_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	G_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	G_GPIO_InitStructure.GPIO_Pin= GPIO_Pin_2;
	
	GPIO_Init(GPIOG,&G_GPIO_InitStructure);
	
	
	

	
}
