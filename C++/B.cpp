#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
/*
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *LinkList;
int main()
{
    Node *p2,*p3,p4;
    Node c[2]={1,2,3,4};
    p2=c;
    p1=&c[1];
    p4.data=5;
    p4.next=6;
    p3=&p4;
    cout<<p2->data<<","<<p2->next<<endl;
    cout<<p1->data<<","<<p1->next<<endl;
    cout<<p3->data<<","<<p3->next<<endl;
    return 0;
}
*/

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

/*class LinkL
{
    private:

};

*/

int main()
{
    LinkList *L;
    int n=10;
    LinkList p;
    int i;
    srand(time(0));  /*��ʼ�����������*/
    *L=(LinkList )malloc (sizeof (Node) );
    (*L )->next =NULL;  /*�Ƚ���һ����ͷ���ĵ�����*/
    for  (i=0; i<n;  i++ )
    {
        p=(LinkList )malloc (sizeof (Node) );/*�����½��*/
        p->data = rand () %100+1;  /*�������100 ���ڵ�����*/
        p->next =(*L )->next;
        (*L)->next = p;  /*���뵽��ͷ*/
    }
         for  (i=0; i<n;  i++ )
    {
        p=p->next;
        cout<<p->data<<endl;  /*���뵽��ͷ*/
    }

return 0;
}
