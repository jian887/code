#include <iostream.h>
#include <conio.h>           //_getch
#include <iomanip.h>          //setw
#include<stdlib.h>           //exit()����
#include<string>
struct ElemType              // ����Ԫ�ص�����
{
    int sno;
	char name[20];
	int shujuku;
	int shujujiegou;
	int yingyu;
	int tiyu;
	int score;
};
const int MAXSIZE=100;     // ���������

class Sqlist
{
private:
	ElemType  elem[MAXSIZE];
	int length;
public:
		Sqlist( void);
		~Sqlist(){ };
		void  SetData();
		void Insert( int i, ElemType e);
		void PrintOut();
		//void BubbleSort(ElemType elem[],int n);
		void Caculate();
};

Sqlist::Sqlist( ) {length=0;}

void  Sqlist::SetData( )     //�½��ɼ���
{
	cout<<"\n ��������length="<<endl;
	cin>>length;

	for(int i=0;i<length;i++)
	{
		cout<<"\n ����ѧ�ţ�";
		cin>>elem[i].sno;
		cout<<"\n ����������";
		cin>> elem[i].name;
		cout<<"\n �������ݿ�ɼ���=";
		cin>>elem[i].shujuku;
		cout<<"\n �������ݽṹ�ɼ���=";
		cin>>elem[i].shujujiegou;
		cout<<"\n ����Ӣ��ɼ���=";
		cin>>elem[i].yingyu;
        cout<<"\n ���������ɼ���=";
		cin>>elem[i].tiyu;
	}
}
void  Sqlist::Insert( int i, ElemType e)                    //����
{

	if(i<0)
	{
	cout<<"��������"<<endl;
	exit(1);     //�쳣�˳�
	}
  for(int j=length;j>=i;j--)
   elem[j]=elem[j-1];
  elem[i-1]=e;
  length++;

}

/*void Sqlist::BubbleSort(ElemType elem[],int length)
{
	int i=1;
	ElemType temp;
	bool finish=false;
	//score=(3*elem[jshujuku+4*shujujiegou+4*yingyu+2*tiyu)/13;
	while(i<length&&!finish)
	{
		finish=true;
		for(int j=0;j<length-i;j++)
		{
			score=(3*elem[j].shujuku+4*elem[j].shujujiegou+4*elem[j].yingyu+2*elem[j].tiyu)/13;
			if(elem[j+1].score>elem[j+1].score)
			{
		   temp=elem[j+1];
		   elem[j+1]=elem[j];
		   elem[j]=temp;
		   finish=false;
			}
		i++;
		}
	}
}*/

void Sqlist::Caculate()
{
	int i,j;
	int a=0,b=0,c=0;
	int score[20];
	cout<<"xufenji"<<endl;
	for(j=0;j<length;j++)
	{
	score[j]=(3*elem[j].shujuku+4*elem[j].shujujiegou+4*elem[j].yingyu+2*elem[j].tiyu)/13;
	cout<<score[j]<<endl;

	}


/*	ElemType *p;
//	p=new ElemType[length];
 //   for(int j=0;j<length;j++)
//	{
	//	score=(3*elem[j].shujuku+4*elem[j].shujujiegou+4*elem[j].yingyu+2*elem[j].tiyu)/13;
	//	BubbleSort(elem,length);

//	int i=1;
//	ElemType temp;
//	bool finish=false;
	//score=(3*elem[jshujuku+4*shujujiegou+4*yingyu+2*tiyu)/13;
		for(int j=0;j<=length-i;j++)
		{
			score=(3*elem[j].shujuku+4*elem[j].shujujiegou+4*elem[j].yingyu+2*elem[j].tiyu)/13;
		if(elem[j+1].score>elem[j].score)
			{
		   temp=elem[j+1];
		   elem[j+1]=elem[j];
		   elem[j]=temp;
		   finish=false;
		}
			i++;
	}*/

	 for ( i = 0; i < length; i++)
    {
        for ( j = i + 1; j < length; j++)
        {
            if (score[i]>score[j])
            {
                int temp = score[i];
                score[i] =score[j];
                score[j]= temp;

				temp = elem[i].sno;
                elem[i].sno = elem[j].sno;
                elem[j].sno= temp;
				
				char *elems;       
				elems = new char[20];
				strcpy(elems,elem[i].name);
				strcpy(elem[i].name,elem[j].name);
				strcpy(elem[j].name,elems);

               temp = elem[i].shujuku;
                elem[i].shujuku = elem[j].shujuku;
                elem[j].shujuku= temp;

				 temp = elem[i].shujujiegou;
                elem[i].shujujiegou = elem[j].shujujiegou;
                elem[j].shujujiegou= temp;

				 temp = elem[i].yingyu;
                elem[i].yingyu = elem[j].yingyu;
                elem[j].yingyu= temp;

				 temp = elem[i].tiyu;
                elem[i].tiyu = elem[j].tiyu;
                elem[j].tiyu= temp;

            }
            //ÿ��i�����Ԫ�ر�length[i]С�ͽ�����
        }
    }


	for(j=0;j<length;j++){
			cout<<"      "<<"���"<<"       "<<"ѧ��"<<"      "<<"����"<<"     "<<"���ݿ�ɼ�"<<"     "<<"���ݽṹ�ɼ�"<<"    "<<"Ӣ��ɼ�"<<"   "<<"�����ɼ�"<<"   "<<"ѧ�ּ���"<<endl;
		    cout<<setw(34)<<a<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
	}


	cout<<endl;
	for(j=0;j<length;j++){

		if(score[j]>=90)
		{	cout<<"���һ�Ƚ�ѧ���ѧ����Ϣ��";
			a++;
			cout<<"      "<<"���"<<"       "<<"ѧ��"<<"      "<<"����"<<"     "<<"���ݿ�ɼ�"<<"     "<<"���ݽṹ�ɼ�"<<"    "<<"Ӣ��ɼ�"<<"   "<<"�����ɼ�"<<"   "<<"ѧ�ּ���"<<endl;
		    cout<<setw(34)<<a<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
		}
		else if(score[j]>83&&score[j]<90)
		{
			cout<<"��ö��Ƚ�ѧ���ѧ����Ϣ��";
			b++;
			cout<<"      "<<"���"<<"       "<<"ѧ��"<<"      "<<"����"<<"     "<<"���ݿ�ɼ�"<<"     "<<"���ݽṹ�ɼ�"<<"    "<<"Ӣ��ɼ�"<<"   "<<"�����ɼ�"<<"   "<<"ѧ�ּ���"<<endl;
	        cout<<setw(34)<<b<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
		}
		else if(score[j]>75&&score[j]<83)
		{
			cout<<"������Ƚ�ѧ���ѧ����Ϣ��";
			c++;
			cout<<"      "<<"���"<<"       "<<"ѧ��"<<"      "<<"����"<<"     "<<"���ݿ�ɼ�"<<"     "<<"���ݽṹ�ɼ�"<<"    "<<"Ӣ��ɼ�"<<"   "<<"�����ɼ�"<<"   "<<"ѧ�ּ���"<<endl;
	        cout<<setw(34)<<c<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
        }

	}

	cout<<"���һ�Ƚ���ѧ������Ϊ��"<<a<<endl;
	cout<<"��ö��Ƚ���ѧ������Ϊ��"<<b<<endl;
	cout<<"������Ƚ���ѧ������Ϊ��"<<c<<endl;
}
void Sqlist::PrintOut()
{
	cout<<"       "<<"ѧ��"<<"      "<<"����"<<"    "<<"���ݿ�ɼ�"<<"   "<<"���ݽṹ�ɼ�"<<"   "<<"Ӣ��ɼ�"<<"   "<<"�����ɼ�"<<"   "<<"ѧ�ּ���"<<endl;
	for(int k=0; k<length;k++)
	{
		cout<<setw(10)<<elem[k].sno<<setw(10)<<elem[k].name<<setw(10)<<elem[k].shujuku<<setw(10)<<elem[k].shujujiegou<<setw(12)<<elem[k].yingyu<<setw(15)<<elem[k].tiyu<<setw(12)<<(3*elem[k].shujuku+4*elem[k].shujujiegou+4*elem[k].yingyu+2*elem[k].tiyu)/13<<endl;
	}
}

int main()
{
	int i,k;  ElemType e;
    Sqlist  as;
	cout<<"\n            16���������ѧ���ɼ���";
	do{
         cout<<"\n\n";
		 cout<<"\n\n  ******************************";
         cout<<"\n\n  *  1. �½�һ��ѧ���ɼ���     *";
         cout<<"\n\n  *  2. ����һ��ѧ����Ϣ       *";
         cout<<"\n\n  *  3. �����ѧ����Ϣ         *";
         cout<<"\n\n  *  4. ��������               *";
         cout<<"\n\n  ******************************";
         cout<<"\n    ���������ѡ��(1,2,3,4)";  cin>>k;
	     switch(k)
		 {
         case 1:
			 {
				 as.SetData();
				 as.PrintOut();
			 }
			 break;
	     case 2:
		  {
		           cout<<"\n �����λ�ã� i="; cin>>i;
                   cout<<"\n ѧ�ţ�"; cin>>e.sno;
                   cout<<"\n ������"; cin>>e.name;
                   cout<<"\n ���ݿ�ɼ���"; cin>>e.shujuku;
				   cout<<"\n ���ݽṹ�ɼ���"; cin>>e.shujujiegou;
				   cout<<"\n Ӣ��ɼ���"; cin>>e.yingyu;
				   cout<<"\n �����ɼ���"; cin>>e.tiyu;
				   as.Insert(i,e);
				   as.PrintOut();
		  }
		  break;
	     case 3:
			      as.Caculate();
		  break;
	     default:
		  break;
		 }
	}while(k>=1&&k<=3);
	cout<<"\n     �ټ����������������";
	_getch();
	return 0;
}


