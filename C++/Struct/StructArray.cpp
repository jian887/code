#include<iostream>

using namespace std;

struct Queue
{
    char customer;
    int time;
};

class Table
{
private:
    Queue q;
    Queue p[20];
    int k;
public:
    Table();
    void fun();
    void fun_2(Queue w);
};


Table::Table() {}

void Table::fun()
{
    //结构体
    q.customer = '1';
    q.time = 1;
    cout<<q.customer<<","<<q.time<<endl;

    //结构体数组1
    p[0].customer = '1';
    p[0].time = 1;
    cout<<p[0].customer<<","<<p[0].time<<endl;

    //结构体数组2
    for(int i=0 ; i<10 ; i++)
    {
        p[i].customer = '1';
        p[i].time = 1;
        cout<<p[i].customer<<","<<p[i].time<<endl;

    }
}

void Table::fun_2(Queue w)
{
    cout<<w.customer<<","<<w.time<<endl;

}

int main()
{
    Queue w;
    Table t;
    w.customer = 'a';
    w.time = 12;
    t.fun();
    t.fun_2(w);
    return 0;
}
