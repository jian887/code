#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;
//---------------------------------------------------------------------------
typedef int KeyType;       // 关键字的类型
const int MAXSIZE=100;     // 数组的容量
struct ElemType            //学生的记录信息
   { KeyType  key ;        //学号
     char name[8];         //姓名
     int english;          //成绩
     int math;             //成绩
   } ;
class SqHash
  { private:
      ElemType *ht;     // 哈希表数组
      int length;       // 哈希表容量
      KeyType   p;      // 除留余数法的大质数
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

   cout<<"\n  请逐一输入各个学号（关-1结束）："<<endl;
   cin>>K;
   cout<<K;
    while(K!=-1)
    {  cout<<K<<endl;
        i=find(K);
       if(i==-1)  cout<<"\n   成功查找到,不再插入！";
        else // if(i!=-32767)
            {
                cout<<i;
                  cout<<"\n  请输入学生的姓名，英语成绩和高数成绩：";    cin>>na>>en>>ma;
                  ht[i].key=K;
                  strcpy(ht[i].name,na);     //用串拷贝赋值
                  ht[i].english=en;
                  ht[i].math=ma;              //　插入学生记录K
                  cout<<"\n   插入成功！" ;
                  cout<<"\n  请逐一输入各个学号（关键字值）（-1结束）："; cin>>K;
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
    cout<<"\n  i="<<i<<"   学号："<<setw(6)<<ht[i].key<<"   姓"<<setw(6)<<ht[i].name
  <<"   英语成绩："<<setw(6)<<ht[i].english<<"   高数成绩："<<setw(6)<<ht[i].math;
}
int main()
{  int p0,n0;
   cout<<"\n  请输入n值（n值应是记录总数的1.3-1.5倍)"; cin>>n0;
   cout<<"\n  请输入P值（应是不大于n 的大质数）："; cin>>p0;
   SqHash  ha(n0,p0);
   int key;
   int k;
   do { cout<<"\n\n\n";
        cout<<"\n       1. 建立哈希表（开放地址法）  ";
        cout<<"\n       2. 在哈希表中查找某位学生 ";
        cout<<"\n       3. 输出哈希表";
        cout<<"\n       4. 结束";
        cout<<"\n=======================================";
        cout<<"\n       输入您的选择(1,2,3,4):"; cin>>k;
       switch(k)
	         { case 1:{  ha.creat_hash();
                     }  break;
	          case 2:{  cout<<"\n  请输入待查找的学生学号：";  cin>>key;

                    int i=ha.find(key);
                    if(i!=-32767) cout<<"\n  此学生"<<key<<"  不存在！" ;
                    }   break;
	         case 3:{ ha.PrintOut(); }  break;
	         }
     }while(k>=1&&k<=3);
   _getch();        return 0;
}
