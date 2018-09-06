#include<iostream>
#include<string.h>
#include<conio.h>
//题目三、哈希表存储的电话号码查询
//基本要求：
//	设每个记录有以下数据项：用户名、电话、地址；
//	从键盘输入各记录，以电话号码为关键字建立哈希表；
//	采用链地址法方法解决冲突；
//	能够查找并显示给定电话号码的相关记录。
//
using namespace std;

struct PhoneList[200];
struct PhoneList{
    int phoneKey;
    char [20] name;
    char [20] address;
    struct PhoneList *next;
};

class SqHash{
private:
    PhoneList *pl;
    int length;
    int p;
public:
    SqHash(int n,int p);
    ~SqHash(){delete ht[];length = 0;}
    createHash();
    insertHash();
    findHash();
    printHash();
};

SqHash::SqHash(int n,int p)
{
    length=n;  p=p;
   ht=new ElemType[length];
   for(int i=0;i<length;i++)pl[i].key=0;
}


void Sqhash::createHash(){
    pl[i]
}


int main()
{
    int length,p;
    SqHash sqhash;
    cin>>length;
    cin>>p;
    sqhash(length,p);

    return 0;
}



