#include<iostream>


using namespace std;


typedef struct Node
{
    int data;
    int next;
}Node;
Node *p1;
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




