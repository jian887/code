#include<iostream>
using namespace std;

struct point{
    int data;
    struct point *next;
};

class Linklist{
private:
    point *head;
    int length;
public:
    Linklist();
    void create_1();
    void print_1();
    int getQueueLength(point *pointHead);
};

Linklist::Linklist(){}

void Linklist::create_1()
{
    cout<<"12"<<endl;
    length = 10;
    point *p,*q;
    head = new point[100];
    head->next = NULL;
    p = head;
    for(int i=0 ;i<length ;i++){
        q = new point[100];
        q->data = i;
        cout<<q->data<<endl;
        q->next = NULL;
        p->next = q;
        cout<<p->next<<endl;
        p = q;
    }
    cout<<","<<head->next->data<<endl;
    cout<<","<<head->next->next->data<<endl;
    cout<<","<<head->next->next->next->data<<endl;
}

void Linklist::print_1()
{

cout<<"printf"<<endl;
    //length = 10;
    int length;
    point *tail;
    tail = new point[100];
    tail = head;
    while(tail!=NULL)
    {
        if(tail->next==NULL)
        cout<<tail->data<<endl;
        else
        cout<<tail->data<<endl;
        tail = tail->next;
    }
    length = getQueueLength(head);
    cout<<"����"<<length<<endl;
}

int Linklist::getQueueLength(point *pointHead)
{
    point *point_1;
    point_1 = new point[10];
    point_1->next = NULL;
    int length = 0;
    point_1 = pointHead;

    while(point_1->next != NULL)
    {
        point_1 = point_1->next;
        length++;
    }
    return length;
}

int main(){
    Linklist l;
    l.create_1();
    l.print_1();

    point p,q;
    p.data = 12;
    //q->data = 15;
    cout<<p.data<<endl;
    //cout<<q.data<<endl;

    return 0;
}










