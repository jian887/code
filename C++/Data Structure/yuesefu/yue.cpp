#include<iostream>
#include <windows.h>
#include<stdlib.h>
using namespace std;

/*******************
Node类的构造函数，初始化结点数据
*/////////////////////
/*  双向循环链表的结点类 */
class Node                 //
{
	friend class Doublelist;
      public:
		  Node();
		  int data;
		  Node *prior;      
		  Node *next;
};
/*  双向循环链表类 */
class Doublelist
{
      public:
		  Doublelist();
		  void Doublenx();
		  void Doublezx();
		  void Creatlist(Doublelist &L);
		  int getLength(Doublelist &L);
	  private:
		  Node *Head;
};

Node::Node()
{
	data=0;
	prior=NULL;
	next=NULL;
}

/**************
Linklist类的构造函数，初始化首节点数据
*****************/
Doublelist::Doublelist()
{
	Head=NULL;
}

/*********************
建立双向循环链表
************************/
void Doublelist::Creatlist(Doublelist &L)
{
	cout<<"请输入双向生死游戏的总人数N:";
	int n;
	cin>>n;
	Node *p,*s;
	for(int i=1;i<=n;i++)
	{
		p=new Node;
		p->data=i;
		p->next=NULL;
		if(i==1)
		{
			L.Head=p;
			p->prior=NULL;
			s=L.Head;
		}
		else
		{
			s->next=p;
			p->prior=s;
			s=s->next;
		}
	}
	p->next=L.Head;
	L.Head->prior=p;
}

/******************
获取双向循环链表的长度
********************/
int Doublelist::getLength(Doublelist &L)
{
	Node *p=L.Head;
	int count=0;
	while(p->next!=L.Head)
	{
		count++;
		p=p->next;
	}
	count++;
	return count;
}

/****************************
实现约瑟夫正序模式
**************************/
void Doublelist::Doublezx()
{
	int a=1000;
	cout<<"现有N人围成一圈，从第S个人开始依次报数，正向报M的人出局，再由下一个人开始报数,";
	cout<<"如此循环，直到剩下K个乘客为止."<<endl<<endl;
	Doublelist L;
	L.Creatlist(L);
	cout<<"请输入游戏开始的位置S:";
	int s;
	cin>>s;

	cout<<"请输入正向的死亡数字M:";
	int m;
	cin>>m;

	cout<<"请输入剩余的生者人数K:";
	int k;
	cin>>k;
	cout<<endl;
	
	if((k>L.getLength(L))||(s<1)||(s>L.getLength(L)))
	{
		cout<<"参数不合法！"<<endl;
		exit(1);
	}
	Node *p,*q,*r;
	p=L.Head;
	for(int i=0;i<s-1;i++) //寻找S结点
	{
		p=p->next;
	}
	int t=1;
	while(k<L.getLength(L))
	{
				Sleep(a);
		if(t) //选择游戏方向
		{
			for(int j=0;j<m-1;j++) //报数 找出M结点
			{
				q=p;
				p=p->next;
			}
			if(p==L.Head) //元素出列
			{
				r=p;
				L.Head=p->next;
				q->next=p->next;
				p->next->prior=q;
				p=p->next;
			}
			else
			{
				r=p;
				q->next=p->next;
				p->next->prior=q;
				p=p->next;
			}
			cout<<"第"<<t<<"个死者的位置是:"<<'\t'<<r->data<<endl;
			t++;
		}
		
	}
	cout<<endl<<"最后剩下"<<'\t'<<L.getLength(L)<<"人"<<endl;
	cout<<"剩余的生者位置为:"<<endl;
	p=L.Head;
	while(p->next!=L.Head)
	{
				Sleep(a);
		cout<<p->data<<'\t';
		p=p->next;
	}
	if(p)
	cout<<p->data<<'\t';
	cout<<endl;
	cout<<"请选择1~2执行约瑟夫游戏模式，选择3退出游戏";
}

/****************************
实现约瑟夫逆序模式
**************************/
void Doublelist::Doublenx()
{
	int a=1000;
	cout<<"现有N人围成一圈，从第S个人开始依次报数,逆时针数到第W人出局";
	cout<<"。在从他逆时针的下一个人数起.";;
	cout<<"如此循环，直到剩下K个乘客为止."<<endl<<endl;
	Doublelist L;
	L.Creatlist(L);
	cout<<"请输入游戏开始的位置S:";
	int s;
	cin>>s;

	cout<<"请输入逆向的死亡数字W:";
	int w;
	cin>>w;

	cout<<"请输入剩余的生者人数K:";
	int k;
	cin>>k;
	cout<<endl;
	
	if((k>L.getLength(L))||(s<1)||(s>L.getLength(L)))
	{
		cout<<"参数不合法！"<<endl;
		exit(1);
	}
	Node *p,*q,*r;
	p=L.Head;
	for(int i=0;i<s-1;i++) //寻找S结点
	{
		p=p->next;
	}
	int t=1;
	while(k<L.getLength(L))
	{
		Sleep(a);
		if(t!=0)
		{
		    for(int j=0;j<w-1;j++) //报数 找出M结点
			{
			    q=p;
		     	p=p->prior;
			}
	     	if(p==L.Head) //元素出列
			{
		    	r=p;
		    	L.Head=p->prior;
		    	q->prior=p->prior;
				p->prior->next=q;
		    	p=p->next;
			}
	    	else
			{
				r=p;
		    	q->prior=p->prior;
				p->prior->next=q;
		    	p=p->prior;
			}
	    	cout<<"第"<<t<<"个死者的位置是:"<<'\t'<<r->data<<endl;
		    t++;
		}
	}
	cout<<endl<<"最后剩下"<<'\t'<<L.getLength(L)<<"人"<<endl;
	cout<<"剩余的生者位置为:"<<endl;
	p=L.Head;
	while(p->next!=L.Head)
	{
		Sleep(a);
		cout<<p->data<<'\t';
		p=p->next;
	}
	if(p)
	cout<<p->data<<'\t';
	cout<<endl;
	cout<<"请选择1~2执行约瑟夫游戏模式，选择3退出游戏";
}

/*****
主函数
******/
void main()
{
	Doublelist z;
	int i;
	cout<<"                       约瑟夫生者死者游戏"<<endl;
	cout<<"                         1.选择顺时针"<<endl;
	cout<<"                         2.选择逆时针"<<endl;
	cout<<"                         3.退出程序"<<endl;
	cout<<"             请选择1~2执行约瑟夫游戏模式，选择3退出游戏";
	
	do
	{
		cin>>i;
		switch(i)
		{
		   case 1: z.Doublezx(); break;
		   case 2: z.Doublenx(); break; 
		}
	}while(i>0&&i<4);
	
}
