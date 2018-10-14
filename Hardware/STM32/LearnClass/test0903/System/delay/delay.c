#include "delay.h"
#include "stm32f10x.h"

void Delay(__IO u32 nCount)   //ÑÓÊ±º¯Êý,1,000,000´ó¸Å100ms
{
	for(; nCount != 0; nCount--);
}
