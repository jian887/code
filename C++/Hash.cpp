#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;
//---------------------------------------------------------------------------
typedef int KeyType;       // �ؼ��ֵ�����
const int MAXSIZE=100;     // ���������
struct ElemType            //ѧ���ļ�¼��Ϣ
   { KeyType  key ;        //ѧ��
     char name[8];         //����
     int english;          //�ɼ�
     int math;             //�ɼ�
   } ;
class SqHash
  { private:
      ElemType *ht;     // ��ϣ������
      int length;       // ��ϣ������
      KeyType   p;      // �����������Ĵ�����
    public:
      SqHash( int n1,int p1);
      ~SqHash(){delete []ht;  length=0;};
      int  find( int K );
      void  creat_hash();
      void PrintOut();
};
//-------------------------------------------------------------
SqHash::SqHash(int n1,int p1)
 { length=n1;  p=p1;
   ht=new ElemType[length];
   for(int i=0;i<length;i++)ht[i].key=0;
  }
void  SqHash::creat_hash()
 { int i,K,en,ma;char na[8];

   cout<<"\n  ����һ�������ѧ�ţ���-1��������"<<endl;
   cin>>K;
   cout<<K;
    while(K!=-1)
    {  cout<<K<<endl;
        i=find(K);
       if(i==-1)  cout<<"\n   �ɹ����ҵ�,���ٲ��룡";
        else // if(i!=-32767)
            {
                cout<<i;
                  cout<<"\n  ������ѧ����������Ӣ��ɼ��͸����ɼ���";    cin>>na>>en>>ma;
                  ht[i].key=K;
                  strcpy(ht[i].name,na);     //�ô�������ֵ
                  ht[i].english=en;
                  ht[i].math=ma;              //������ѧ����¼K
                  cout<<"\n   ����ɹ���" ;
                  cout<<"\n  ����һ�������ѧ�ţ��ؼ���ֵ����-1��������"; cin>>K;
}
}
 }
int  SqHash::find (int K)
 {
	/*int i = K%p;
	if (ht[i].key==K)
	{
		return -32767;
	}
	else {
		while(ht[i].key!=K){
			i = (i+1)%p;
			if (ht[i].key == K) return -32767;
			else if(i>7){
	//while (ht[i].key!=0)
//		i = (i+1)%p;
				return i;
			}
			i++;
		}
	}
	return 23;*/
	int addr = K%p;
    if (ht[addr].key==K) {
                addr = -1;
        return addr;
    }

    else
    {
        //addr = (addr + 1) % p;
        while(ht[addr].key!=K) {
            addr = (addr + 1) % p;
            if (ht[addr].key==K)  {
                   addr = -1;
                   return addr;
            }
            else if(addr==7){
                return addr;
            }
            addr++;
        }

    }
    return 0;
}
void  SqHash::PrintOut()
{ int i;
  for (i=0;i<length; i++)
    cout<<"\n  i="<<i<<"   ѧ�ţ�"<<setw(6)<<ht[i].key<<"   ��"<<setw(6)<<ht[i].name
  <<"   Ӣ��ɼ���"<<setw(6)<<ht[i].english<<"   �����ɼ���"<<setw(6)<<ht[i].math;
}
int main()
{  int p0,n0;
   cout<<"\n  ������nֵ��nֵӦ�Ǽ�¼������1.3-1.5��)"; cin>>n0;
   cout<<"\n  ������Pֵ��Ӧ�ǲ�����n �Ĵ���������"; cin>>p0;
   SqHash  ha(n0,p0);
   int key;
   int k;
   do { cout<<"\n\n\n";
        cout<<"\n       1. ������ϣ�����ŵ�ַ����  ";
        cout<<"\n       2. �ڹ�ϣ���в���ĳλѧ�� ";
        cout<<"\n       3. �����ϣ��";
        cout<<"\n       4. ����";
        cout<<"\n=======================================";
        cout<<"\n       ��������ѡ��(1,2,3,4):"; cin>>k;
       switch(k)
	         { case 1:{  ha.creat_hash();
                     }  break;
	          case 2:{  cout<<"\n  ����������ҵ�ѧ��ѧ�ţ�";  cin>>key;

                    int i=ha.find(key);
                    if(i!=-32767) cout<<"\n  ��ѧ��"<<key<<"  �����ڣ�" ;
                    }   break;
	         case 3:{ ha.PrintOut(); }  break;
	         }
     }while(k>=1&&k<=3);
   _getch();        return 0;
}
