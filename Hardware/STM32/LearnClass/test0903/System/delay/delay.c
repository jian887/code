#include "delay.h"
#include "stm32f10x.h"

void Delay(__IO u32 nCount)   //��ʱ����,1,000,000���100ms
{
	for(; nCount != 0; nCount--);
}
