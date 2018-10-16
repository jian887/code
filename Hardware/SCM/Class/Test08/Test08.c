#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int

sbit RW = P3^6;
sbit RS = P3^5;
sbit EN	= P3^4;

void delay (uint i)
{
	uchar t;
	while(i--){
		for(t =0;t<120;t++);a
	}
}

void Read_busy()
{
	ubchar;
	P0 = 0xff;
	RS = 0;
	RW = 1;
	do
	{
		EN = 1;
		busy = P0;
		EN = 0;
		}while(busy&0x80):
}

void write_cmd(uchar cmd)
{
	Read_busy();
	RS = 0;
	RW = 0;
	P0 =cmd;
	EN = 1;
	EN = 0;
}

void write_data(uchar data)
{
	Read_busy();
	RS = 1;
	RW = 1;
	P0 = data;
	EN = 1;
	EN = 0;
}
void init_lcd()
{
	write_cmd(0x38);
	write_cmd(0x01);
	write_cmd(0x06);
	write_cmd(0x0c);
}
void main()
{
	init();
	write_data();

}
