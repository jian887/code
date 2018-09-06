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
    srand(time(0));  /*初始化随机数种子*/
    *L=(LinkList )malloc (sizeof (Node) );
    (*L )->next =NULL;  /*先建立一个带头结点的单链表*/
    for  (i=0; i<n;  i++ )
    {
        p=(LinkList )malloc (sizeof (Node) );/*生成新结点*/
        p->data = rand () %100+1;  /*随机生成100 以内的数字*/
        p->next =(*L )->next;
        (*L)->next = p;  /*插入到表头*/
    }
         for  (i=0; i<n;  i++ )
    {
        p=p->next;
        cout<<p->data<<endl;  /*插入到表头*/
    }

return 0;
}
