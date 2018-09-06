#include<iostream>
#include <windows.h>
#include<stdlib.h>
using namespace std;

/*******************
Node��Ĺ��캯������ʼ���������
*/////////////////////
/*  ˫��ѭ������Ľ���� */
class Node                 //
{
	friend class Doublelist;
      public:
		  Node();
		  int data;
		  Node *prior;      
		  Node *next;
};
/*  ˫��ѭ�������� */
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
Linklist��Ĺ��캯������ʼ���׽ڵ�����
*****************/
Doublelist::Doublelist()
{
	Head=NULL;
}

/*********************
����˫��ѭ������
************************/
void Doublelist::Creatlist(Doublelist &L)
{
	cout<<"������˫��������Ϸ��������N:";
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
��ȡ˫��ѭ������ĳ���
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
ʵ��Լɪ������ģʽ
**************************/
void Doublelist::Doublezx()
{
	int a=1000;
	cout<<"����N��Χ��һȦ���ӵ�S���˿�ʼ���α���������M���˳��֣�������һ���˿�ʼ����,";
	cout<<"���ѭ����ֱ��ʣ��K���˿�Ϊֹ."<<endl<<endl;
	Doublelist L;
	L.Creatlist(L);
	cout<<"��������Ϸ��ʼ��λ��S:";
	int s;
	cin>>s;

	cout<<"�������������������M:";
	int m;
	cin>>m;

	cout<<"������ʣ�����������K:";
	int k;
	cin>>k;
	cout<<endl;
	
	if((k>L.getLength(L))||(s<1)||(s>L.getLength(L)))
	{
		cout<<"�������Ϸ���"<<endl;
		exit(1);
	}
	Node *p,*q,*r;
	p=L.Head;
	for(int i=0;i<s-1;i++) //Ѱ��S���
	{
		p=p->next;
	}
	int t=1;
	while(k<L.getLength(L))
	{
				Sleep(a);
		if(t) //ѡ����Ϸ����
		{
			for(int j=0;j<m-1;j++) //���� �ҳ�M���
			{
				q=p;
				p=p->next;
			}
			if(p==L.Head) //Ԫ�س���
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
			cout<<"��"<<t<<"�����ߵ�λ����:"<<'\t'<<r->data<<endl;
			t++;
		}
		
	}
	cout<<endl<<"���ʣ��"<<'\t'<<L.getLength(L)<<"��"<<endl;
	cout<<"ʣ�������λ��Ϊ:"<<endl;
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
	cout<<"��ѡ��1~2ִ��Լɪ����Ϸģʽ��ѡ��3�˳���Ϸ";
}

/****************************
ʵ��Լɪ������ģʽ
**************************/
void Doublelist::Doublenx()
{
	int a=1000;
	cout<<"����N��Χ��һȦ���ӵ�S���˿�ʼ���α���,��ʱ��������W�˳���";
	cout<<"���ڴ�����ʱ�����һ��������.";;
	cout<<"���ѭ����ֱ��ʣ��K���˿�Ϊֹ."<<endl<<endl;
	Doublelist L;
	L.Creatlist(L);
	cout<<"��������Ϸ��ʼ��λ��S:";
	int s;
	cin>>s;

	cout<<"�������������������W:";
	int w;
	cin>>w;

	cout<<"������ʣ�����������K:";
	int k;
	cin>>k;
	cout<<endl;
	
	if((k>L.getLength(L))||(s<1)||(s>L.getLength(L)))
	{
		cout<<"�������Ϸ���"<<endl;
		exit(1);
	}
	Node *p,*q,*r;
	p=L.Head;
	for(int i=0;i<s-1;i++) //Ѱ��S���
	{
		p=p->next;
	}
	int t=1;
	while(k<L.getLength(L))
	{
		Sleep(a);
		if(t!=0)
		{
		    for(int j=0;j<w-1;j++) //���� �ҳ�M���
			{
			    q=p;
		     	p=p->prior;
			}
	     	if(p==L.Head) //Ԫ�س���
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
	    	cout<<"��"<<t<<"�����ߵ�λ����:"<<'\t'<<r->data<<endl;
		    t++;
		}
	}
	cout<<endl<<"���ʣ��"<<'\t'<<L.getLength(L)<<"��"<<endl;
	cout<<"ʣ�������λ��Ϊ:"<<endl;
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
	cout<<"��ѡ��1~2ִ��Լɪ����Ϸģʽ��ѡ��3�˳���Ϸ";
}

/*****
������
******/
void main()
{
	Doublelist z;
	int i;
	cout<<"                       Լɪ������������Ϸ"<<endl;
	cout<<"                         1.ѡ��˳ʱ��"<<endl;
	cout<<"                         2.ѡ����ʱ��"<<endl;
	cout<<"                         3.�˳�����"<<endl;
	cout<<"             ��ѡ��1~2ִ��Լɪ����Ϸģʽ��ѡ��3�˳���Ϸ";
	
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
