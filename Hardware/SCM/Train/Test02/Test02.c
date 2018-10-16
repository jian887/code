#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int

sbit LED2 = P1^1;
sbit LED4 = P1^3;
sbit LED6 = P1^5;
sbit LED8 = P1^7;

void delay (uint i)
{
    uchar t;
    while(i--) {
        for(t =0; t<120; t++);
    }
}


void main()
{

    while(1)
    {
        LED2 = 0;
        LED4 = 0;
        LED6 = 0;
        LED8 = 0;
        delay(1000);
        LED2 = 1;
        LED4 = 1;
        LED6 = 1;
        LED8 = 1;
        delay(1000);

    }

}



