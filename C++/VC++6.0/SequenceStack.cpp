#include<iostream.h>
#include<conio.h>
#include <iomanip.h>

//using namespace std;
//------------------------------ջ��˳��洢�ṹ---------------------------------------------
typedef int  ElemType;     // ����Ԫ�ص�����
const int MAXSIZE=100;     // ���������
class SqStack
  { private:
      ElemType  elem[MAXSIZE];
      int top;
    public:
      SqStack( void);
      ~SqStack(){};
      int  SqStack::SetEmpty();
      SqStack::push(ElemType e);
      ElemType SqStack::pop();
      void SqStack::PrintOut();
     int SqStack::IsEmpty(void)const ;


};
//-------------------------------------------------------------
SqStack::SqStack( void):top(0){ }
int  SqStack::SetEmpty()
   { return top==0;
   }

SqStack::push(ElemType e)
{
    if(top==(MAXSIZE-1)){
            cout<<"ջ����"<<endl;
    return 0;
    }else{
    elem[++top]=e;
    return 0;
    }
}

ElemType SqStack::pop()
{
    if(top==0)
        return 0;
    else return elem[top--];
}
void SqStack::PrintOut()
  {int k;
   cout<<"\n PrintOut Data:\n" ;
   for(k=top; k>=1;k--) cout<<setw(6)<<elem[k];
   cout<<endl;
 }
int SqStack::IsEmpty(void)const
{ if(top==0) return 1;
     else return 0;
 }
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{ int k;
  ElemType e,x;
  SqStack  as;
   cout<<"\n                           ˳����洢�ṹ��ʾ";
  do{
    cout<<"\n\n";
    cout<<"\n\n    1.����һ������Ԫ��e����ջ��";
    cout<<"\n\n    2.ɾ��һ��Ԫ�أ�������ֵ����ջ��";
    cout<<"\n\n    3..��������";
    cout<<"\n******************************** ";
    cout<<"\n    ���������ѡ��(1,2,3,4,5,6)";    cin>>k;
    switch(k){
       case 1:{cout<<"\n ��ջ������ e=?";
               cin>>e;
               as.push(e);
               as.PrintOut();
              }break;
       case 2:{  cout<<"\n ��ջ";
                 x=as.pop();
                 if(x==0)
                    cout<<"\nջ�ѿ�";
                else
                {
                 cout<<"\n  ��ջԪ����ֵ= "<<x;
                  as.PrintOut();
                  }
             }break;
       default:break;
         } //switch
     cout<<"\n--------------------------------- ";
    }while(k>=1&&k<3);
  cout<<"\n          �ټ�!";
  cout<<"\n     ������������ء�";
  _getch(); return 0;
}