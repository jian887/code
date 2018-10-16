# include <reg52.h>
# include <intrins.h>
#define uchar unsigned char//
#define uint  unsigned int //

sbit we = P2^7; //位选
sbit du = P2^6; //段选
uchar i = 0;

uchar code leddata[]= {

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
    0x77,  //"A"
    0x7C,  //"B"
    0x39,  //"C"
    0x5E,  //"D"
    0x79,  //"E"
    0x71,  //"F"
    0x76,  //"H"
    0x38,  //"L"
    0x37,  //"n"
    0x3E,  //"u"
    0x73,  //"P"
    0x5C,  //"o"
    0x40,  //"-"
    0x00,  //??
    0x00  //???

};

uchar tab [] = {0xfe , 0xfd, 0xfb, 0xf7, 0xef, 0xdf ,0xbf ,0x7f ,0x7f};

uchar temp;

void delay(uint z)
{
    uint x,y;
    for(x = z; x > 0; x--)
        for(y = 114; y > 0 ; y--);
}


void main()
{
    while(1) {
			
			
			
						
//			P0 = 0xfe;//1111 1110 ????????,????????,P0.0??????????????
//			we = 1;//????
//			we = 0;	//????

//			P0 = leddata[1];
//			du = 1;	//????
//			du = 0;	//????
//			delay(2);//??
//			
//			P0 = 0xfd;//1111 1101  ?????????
//			we = 1;	//????
//			we = 0;	//????
//			
//			P0 = leddata[2]; //??2
//			du = 1;//????
//			du = 0;	//????
//			delay(2);//??
//			
//			P0 = 0xfb;// 1111 1011?????????
//			we = 1;	//????
//			we = 0;	//????
//			
//			P0 = leddata[3]; //??3
//			du = 1;//????
//			du = 0;	//????
//			delay(2);//??
//			
//			P0 = 0xf7;//1111 0111  ?????????
//			we = 1;	//????
//			we = 0;	//????
//			
//			P0 = leddata[4]; //??4
//			du = 1;//????
//			du = 0;	//????
//			delay(2);//??
//			
//			P0 = 0xef;//1110 1111  ?????????
//			we = 1;	//????
//			we = 0;	//????
//			
//			P0 = leddata[5]; //??5
//			du = 1;//????
//			du = 0;	//????
//			delay(2);//??
//			
//			P0 = 0xdf;//1101 1111  ?????????
//			we = 1;	//????
//			we = 0;	//????
//			
//			P0 = leddata[6]; //??6
//			du = 1;//????
//			du = 0;	//????
//			delay(2);//??
//			
//			we = 1;	//????
//			P0 = 0xbf;//1011 1111  ?????????
//			we = 0;	//????
//			
//			P0 = leddata[7]; //??7
//			du = 1;//????
//			du = 0;	//????
//			delay(2);//??
//			
//			P0 = 0x7f;//0111 1111  ?????????
//			we = 1;	//????
//			we = 0;	//????
//			
//			P0 = leddata[8]; //??8
//			du = 1;//????
//			du = 0;	//????
//			delay(2);//??	
		  temp = 0xfe;  // for 循环显示
      //P0 = 0xfe; //1111 1110  1111 1101
			for(i= 0;i<8;i++)
			{
				P0 = temp;
				temp = _crol_(temp,1);
				we = 1;
        we = 0;
        P0 = leddata[i];
        du = 1;
        du = 0;
        delay(2);
			} 
    }
}

// 复杂写法
//	for(i= 0;i<10;i++){
//
//	P0 = 0xfe;
//	we = 1;
//	we = 0;
//	P0 = leddata[i];
//	du = 1;
//	du = 0;
//	delay(500);
//
