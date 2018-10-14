#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int
	
sbit S0 = P3^0;
sbit S1 = P3^1;
sbit S2 = P3^2;
sbit S3 = P3^3;


sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;

void delay (uint i)
{
	uchar t;
	while(i--){
		for(t =0;t<120;t++);
	}
}


void main()
{
	
	char state;
	do{
		P3 = 0xff;
		state = P3;
//		state = state&0x0f; 
		state = state&0x03;
		
		// s1 1111 1110  0000 1110 0e 14
    // s2 1111 1101  0000 1101 0d 13
    // s3 1111 1011  0000 1011 0b 11
    // s4 1111 0111	 0000 0111 07 7
		//             &0f
		
		// state = 0000 0100
		switch(state)
	{
		
//   		case 14: P1 = 0xfe;break;
//			case 13: P1 = 0xfd;break;
//			case 11: P1 = 0xfb;break;
//			case 7: P1 = 0xf7;break;
		
//			case 0: P1 = 0xfe;break;
//			case 1: P1 = 0xfd;break;
//			case 2: P1 = 0xfb;break;
//			case 3: P1 = 0xf7;break;
		}	
	}while(1);

}	




