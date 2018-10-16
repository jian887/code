#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int
	
void delay (uint i)
{
	uchar t;
	while(i--){
		for(t =0;t<120;t++);
	}
}
		
void main(){
		//P1=0xfe; //1111 1110  
	  //P1=0x7f; //0111 1111
	  
	
			uchar j,temp;
 
	  while(1){
	    temp = 0xfe;
			for(j = 0 ; j<7 ;j++)
			{
				P1 = temp;
				delay(500);
				temp = _crol_(temp,1);
			}
		
			for(j = 0 ; j<7 ;j++)
			{
				P1 = temp;
				delay(500);
				temp = _cror_(temp,1);
				
			}
		}
}

/*
#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int
	
uchar tab [] = {0xfe , 0xfd, 0xfb, 0xf7, 0xef, 0xdf ,0xbf ,0x7f ,0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
uint a; 
void delay (uint i)
{
	uchar t;
	while(i--){
		for(t =0;t<120;t++);
	}
}
		
void main(){
		//P1=0xfe; //1111 1110  
	  //P1=0x7f; //0111 1111
	  P1 = 0xfe;
 
	  while(1){
		delay(500);
		//P1 = _crol_(P1,1);   
		//P1 = _cror_(P1,1);    54
		//1111 1101
		
			for(a = 0 ; a <16 ;a++)
			{
				P1 = tab[a];
				delay(500);
				
			}
			

		}
}
*/