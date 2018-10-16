/*��ʱ��1����ʱģʽ ����ģʽ1 16λ��������
��ʱ20���ʹ�ܷ�����*/
#include <reg52.h> //51ͷ�ļ�
#include <intrins.h>
#define uchar unsigned char//�궨��
#define uint  unsigned int//�궨��
sbit we = P2^7;//λ���������λѡ�������ӿ�
sbit du = P2^6;//λ��������ܶ�ѡ�������ӿ�
sbit beep = P2^3;//�������ӿ�

//����ܶ�ѡ��
uchar code leddata[]={ 
 
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
                0x00,  //Ϩ��
                0x00  //�Զ���
 
                         };

//���뼶��ʱ����
void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--);
}

//��λ����ܶ�̬��ʾ����
void display(uchar i)
{
	uchar shi, ge;
	shi = i / 10;//��ģ  i����10ȡ�̵���������
	ge  = i % 10;//����  i����10ȡ��������

	P0 = 0xff; //�������
	we = 1;//��λѡ
	P0 = 0xbf;//1111 1110 ֻѡͨ��һλ�����
	we = 0;	//�ر�λѡ

	du = 1;	//�򿪶�ѡ
	P0 = leddata[shi];
	du = 0;	//�رն�ѡ
	delay(5);//��ʱ5����
	
	P0 = 0xff;//�������
	we = 1;	//��λѡ
	P0 = 0x7f;//1111 1101  ֻѡͨ�ڶ�λ�����
	we = 0;	//�ر�λѡ
	
	du = 1;//�򿪶�ѡ
	P0 = leddata[ge]; 
	du = 0;	//�رն�ѡ
	delay(5);//��ʱ5����	
}

void main()
{
	  uchar j,temp;
		uchar a; //50��������
		uchar b;//�����
		TR1 = 1;//����T1
		TMOD = 0x10;//T1Ϊ��ʱ��������ģʽ1 16λ������
		TH1 = 0x4b;
		TL1 = 0xfc;//0x4bfc	��ʱ50ms				
		while(1)
		{
			if(TF1 == 1)//�ж�T1�Ƿ����
			{
				TH1 = 0x4b;
				TL1 = 0xfc;//0x4bfc	��ʱ50ms
				TF1 = 0;//��������´��ж�
				a++;//50���������1	
			}
			if(a == 20)//�ж��Ƿ�1��
			{
				a = 0;//��������´μ�¼50ms�Ĵ���
				b++;//���1
			}

			display(b);//��ʾ���ֵ

			if(b == 60)//����Ƿ�20��
			{
				TR1 = 0;//ʱ�䵽�رն�ʱ��1
			  
				temp = 0xfe;
				while(1){
					
					for(j =0 ;j<7;j++)
					{
						P1 = temp;
						delay(1000);
			  temp = _crol_(temp,1);
				
					}
				}
			}

			
		}
}