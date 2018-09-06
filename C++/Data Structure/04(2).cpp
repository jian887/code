#include <iostream.h>
#include <conio.h>           //_getch
#include <iomanip.h>          //setw
#include<stdlib.h>           //exit()函数
#include<string>
struct ElemType              // 数据元素的类型
{
    int sno;
	char name[20];
	int shujuku;
	int shujujiegou;
	int yingyu;
	int tiyu;
	int score;
};
const int MAXSIZE=100;     // 数组的容量

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

void  Sqlist::SetData( )     //新建成绩表
{
	cout<<"\n 输入人数length="<<endl;
	cin>>length;

	for(int i=0;i<length;i++)
	{
		cout<<"\n 输入学号：";
		cin>>elem[i].sno;
		cout<<"\n 输入姓名：";
		cin>> elem[i].name;
		cout<<"\n 输入数据库成绩：=";
		cin>>elem[i].shujuku;
		cout<<"\n 输入数据结构成绩：=";
		cin>>elem[i].shujujiegou;
		cout<<"\n 输入英语成绩：=";
		cin>>elem[i].yingyu;
        cout<<"\n 输入体育成绩：=";
		cin>>elem[i].tiyu;
	}
}
void  Sqlist::Insert( int i, ElemType e)                    //增加
{

	if(i<0)
	{
	cout<<"操作有误"<<endl;
	exit(1);     //异常退出
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
            //每次i后面的元素比length[i]小就交换。
        }
    }


	for(j=0;j<length;j++){
			cout<<"      "<<"序号"<<"       "<<"学号"<<"      "<<"姓名"<<"     "<<"数据库成绩"<<"     "<<"数据结构成绩"<<"    "<<"英语成绩"<<"   "<<"体育成绩"<<"   "<<"学分绩："<<endl;
		    cout<<setw(34)<<a<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
	}


	cout<<endl;
	for(j=0;j<length;j++){

		if(score[j]>=90)
		{	cout<<"获得一等奖学金的学生信息：";
			a++;
			cout<<"      "<<"序号"<<"       "<<"学号"<<"      "<<"姓名"<<"     "<<"数据库成绩"<<"     "<<"数据结构成绩"<<"    "<<"英语成绩"<<"   "<<"体育成绩"<<"   "<<"学分绩："<<endl;
		    cout<<setw(34)<<a<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
		}
		else if(score[j]>83&&score[j]<90)
		{
			cout<<"获得二等奖学金的学生信息：";
			b++;
			cout<<"      "<<"序号"<<"       "<<"学号"<<"      "<<"姓名"<<"     "<<"数据库成绩"<<"     "<<"数据结构成绩"<<"    "<<"英语成绩"<<"   "<<"体育成绩"<<"   "<<"学分绩："<<endl;
	        cout<<setw(34)<<b<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
		}
		else if(score[j]>75&&score[j]<83)
		{
			cout<<"获得三等奖学金的学生信息：";
			c++;
			cout<<"      "<<"序号"<<"       "<<"学号"<<"      "<<"姓名"<<"     "<<"数据库成绩"<<"     "<<"数据结构成绩"<<"    "<<"英语成绩"<<"   "<<"体育成绩"<<"   "<<"学分绩："<<endl;
	        cout<<setw(34)<<c<<'\t'<<setw(7)<<elem[j].sno<<setw(10)<<elem[j].name<<setw(10)<<elem[j].shujuku<<setw(15)<<elem[j].shujujiegou<<setw(14)<<elem[j].yingyu<<setw(15)<<elem[j].tiyu<<setw(10)<<score[j]<<endl;
        }

	}

	cout<<"获得一等奖的学生人数为："<<a<<endl;
	cout<<"获得二等奖的学生人数为："<<b<<endl;
	cout<<"获得三等奖的学生人数为："<<c<<endl;
}
void Sqlist::PrintOut()
{
	cout<<"       "<<"学号"<<"      "<<"姓名"<<"    "<<"数据库成绩"<<"   "<<"数据结构成绩"<<"   "<<"英语成绩"<<"   "<<"体育成绩"<<"   "<<"学分绩："<<endl;
	for(int k=0; k<length;k++)
	{
		cout<<setw(10)<<elem[k].sno<<setw(10)<<elem[k].name<<setw(10)<<elem[k].shujuku<<setw(10)<<elem[k].shujujiegou<<setw(12)<<elem[k].yingyu<<setw(15)<<elem[k].tiyu<<setw(12)<<(3*elem[k].shujuku+4*elem[k].shujujiegou+4*elem[k].yingyu+2*elem[k].tiyu)/13<<endl;
	}
}

int main()
{
	int i,k;  ElemType e;
    Sqlist  as;
	cout<<"\n            16级软件工程学生成绩表";
	do{
         cout<<"\n\n";
		 cout<<"\n\n  ******************************";
         cout<<"\n\n  *  1. 新建一个学生成绩表     *";
         cout<<"\n\n  *  2. 增加一个学生信息       *";
         cout<<"\n\n  *  3. 输出奖学金信息         *";
         cout<<"\n\n  *  4. 结束程序               *";
         cout<<"\n\n  ******************************";
         cout<<"\n    请输入你的选择(1,2,3,4)";  cin>>k;
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
		           cout<<"\n 插入的位置， i="; cin>>i;
                   cout<<"\n 学号："; cin>>e.sno;
                   cout<<"\n 姓名："; cin>>e.name;
                   cout<<"\n 数据库成绩："; cin>>e.shujuku;
				   cout<<"\n 数据结构成绩："; cin>>e.shujujiegou;
				   cout<<"\n 英语成绩："; cin>>e.yingyu;
				   cout<<"\n 体育成绩："; cin>>e.tiyu;
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
	cout<<"\n     再见！按任意键结束！";
	_getch();
	return 0;
}


