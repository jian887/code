#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <string.h>
//--------------------------------------------------------------------
struct ElemType              // ����Ԫ�ص�����
{ 
	int numb;
	char name[20];
	int tel;

};

const int MAXSIZE=100;     // ���������

class Sqlist
{
private:
	ElemType elem[MAXSIZE];
	int length;
    public:
		Sqlist( void);
		~Sqlist(){ };
		void  SetData();
		void  Insert( int i, ElemType e);
		ElemType Delet(int i);
		void PrintOut();
};
//-------------------------------------------------------------
Sqlist::Sqlist( ) { length=0;}
void  Sqlist::SetData( )     //��������һ��ͨѶ¼ 
{
	cout<<"\n ��������length="<<endl;
	cin>>length;
	for(int i=0;i<length;i++)
	{ 
		cout<<"\n ����ѧ�ţ�";  
		cin>>elem[i].numb;
		cout<<"\n ����������"; 
		cin>> elem[i].name;
		cout<<"\n ����绰�ţ�="; 
		cin>>elem[i].tel;
	}
}
void  Sqlist::Insert( int i, ElemType e) //����ɴ˺���
{
	//�������1
}
ElemType Sqlist::Delet(int i)
{



	//�������2
   return x;
}
void Sqlist::PrintOut()  //���
 { 
	cout<<"\n ͨѶ¼��������"<<length;
	cout<<"\n PrintOut Data:\n";
	cout<<setw(16)<<"ѧ��"<<setw(20)<<"����"<<setw(20)<<"�绰��"<<endl;
	for(int k=0; k<length;k++)      
	{ 
		cout<<setw(16)<<elem[k].numb<<setw(20)<<elem[k].name<<setw(20)<<elem[k].tel<<endl;
	}
 }
//--------------------------------------------------
int main( )
{ int i,k;  ElemType e,x;
  Sqlist  as;
  cout<<"\n               ͨѶ¼��ʾ";
  do{
      cout<<"\n\n";
      cout<<"\n\n    1. ��������һ��ͨѶ¼�����Ա��� ";
      cout<<"\n\n    2. ����һ������Ԫ�� ";
      cout<<"\n\n    3. ɾ��һ��Ԫ�أ�������ֵ";
      cout<<"\n\n    4. ��������";
      cout<<"\n******************************** ";
      cout<<"\n    ���������ѡ��(1,2,3,4)";  cin>>k;
	  switch(k)
	  { 
	  case 1:
		  {  as.SetData(); as.PrintOut();  }break;
	  case 2:{ cout<<"\n �����λ�ã� i=?"; cin>>i;
                   cout<<"\n ��������� ���=?"; cin>>e.numb;
                   cout<<"\n ��������� ����=?"; cin>>e.name;
                   cout<<"\n ��������� �绰��=?"; cin>>e.tel;
                   as.Insert(i,e);  as.PrintOut();
                 }break;
	  case 3:{ cout<<"\n ɾ���ڼ���Ԫi=?";  cin>>i;
                  x=as.Delet(i);
                  cout<<"\n  ��ɾ����Ԫ����ֵ= "<<setw(10)<<x.numb<<
                  setw(10)<<x.name<<setw(10)<<x.tel;
                  as.PrintOut();
                 }break;
	  default:break;
	  } //switch
  }while(k>=1&&k<4);
  cout<<"\n          �ټ�!";  cout<<"\n     ������������ء�";
  _getch(); return 0;
}//-----------------------------------------------   