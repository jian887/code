#include<iostream>
#include<string>
#include <limits>
using namespace std;

struct Point{
    int data;
    struct Point *next;
};

class LinkList{
private:
    Point *head;
    int length;
public:
    LinkList();
    void create();
    int add();
    int delete_1();
    void print();
};

void LinkList::create()
{
    int i;
    LinkList *p,*q;
    cout<<"length"<<endl;
    cin<<length;
    head = new Point[10];
    p = head;
    for(i=0 ;i<length ;i++){
        q = new Point();
        q->data = i;
        p->next = q;
        p = q;
    }
}

int void

int main()
{
    int s_1,s_2,p_1,p_2;
    LinkList l;
    l.create();
    cout<<"add"<<endl;
    cin>>s_1;
    p_1=l.add();
    cout<<p_1<<endl;
    cout<<"delete"<<endl;
    cin>>s_2;
    p_2=l.delete_1();
    cout<<p_2<<endl;
    return 0;

}
