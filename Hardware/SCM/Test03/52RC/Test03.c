#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int

#define out P0;

uchar seg1 [] = {0xc0 ,0xa4, 0x99, 0x82, 0x80, 0xf9 ,0xb0 ,0x92 ,0xf8 ,0x90 ,0x01};
uchar seg [] =
{
	 0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
	0x01

};
uint a = 0; 

void delay (uint i)
{
	uchar t;
	while(i--){
		for(t =0;t<120;t++);
	}
}

void main()
{
	while(1)
	{
		 = seg [a];
		delay(500);
		a++;
		if(seg[a] == 0x01) a = 0;
	}

}