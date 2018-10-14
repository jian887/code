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

void fmqi()
{
	fmq = ~fmq;
	delay(5000);
}

void main()
{
	fmqi();
	delay(5000);
  fmqi();
	delay(5000);
	
}