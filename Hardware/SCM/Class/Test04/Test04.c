#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int

sbit fmq = P2^3;


void delay (uint i)
{
	uchar t;
	while(i--){
		for(t =0;t<120;t++);
	}
}



int main()
{
	uchar j =0;
 
	fmq = 0;
	delay(1500);
	fmq = 1;
	delay(1500);
	
	fmq = 0;
	delay(1500);
	fmq = 1;
	delay(1500);
	
		fmq = 0;
	delay(1500);
	fmq = 1;
	delay(1500);
	
		fmq = 0;
	delay(1500);
	fmq = 1;
	delay(1500);
	
		fmq = 0;
	delay(1500);
	fmq = 1;
	delay(1500);
	
	
	
}


/*
*/