#include <iostream>
#include <conio.h>
#define MAXSIZE 5
using namespace std;

typedef int ElemType;
class SeQueue
{
private:
    ElemType elem[MAXSIZE];
    int front,rear;
public:
    SeQueue();
    ~SeQueue();
    void Display();
    AddQ(ElemType e);
    ElemType DelQ();
};

SeQueue::SeQueue()
{
    front=0;
    rear=0;
    cout<<"init!"<<endl;
}

SeQueue::~SeQueue()
{};//{ delete [MAXSIZE]Q.elem;}

void SeQueue::Display()
{
    ElemType x;
    int j=0;
    if(rear==front)
    {
        cout<<"QUEUE IS NULL!";
    }
    else
    {
        j=front;
        cout<<"QUEUE: ";
        while(j!=rear)
        {
            x=elem[j];
            cout<<x<<" ";
            j=(j+1)%MAXSIZE;
        }
    }
    cout<<endl;
    j = 0;
    while (j<MAXSIZE){
        cout<<elem[j]<<" ";
        j++;
    }
    cout<<endl;
}

SeQueue::AddQ(ElemType e)
{
    if((rear+1)%MAXSIZE==front)
    {
        cout<<"QUEUE IS FULL!\n";
        return 0;
    }
    else
    {
        elem[rear]=e;
        rear=(rear+1)%MAXSIZE;
        return 0;
    }

}

ElemType SeQueue::DelQ()
{
    int e;
    if(rear==front)
    {
        cout<<"QUEUE IS NULL\n";
        return 0;
    }
    else
    {
        e=elem[front];
        front=(front+1)%MAXSIZE;
        return e;
    }

}

int main(  )
{
    ElemType e;
    SeQueue h;
    int k;
    cout<<"\n                           ���д洢�ṹ��ʾ";
    do
    {
        cout<<"\n\n";
        cout<<"\n\n    1.��������һ������";
        cout<<"\n\n    2.�����������";
        cout<<"\n\n    3.���";
        cout<<"\n\n    4.����";
        cout<<"\n\n    5.��������";
        cout<<"\n******************************** ";
        cout<<"\n    ���������ѡ��(1,2,3,4,5)";
        cin>>k;
        switch(k)
        {
        case 1:
        {

        }
        break;
        case 2:
        {
            h.Display();
        }
        break;
        case 3:
        {
            cout<< "����  data=?";
            cin>>e;
            h.AddQ(e);
            h.Display();
        }
        break;
        case 4:
        {
            e=h.DelQ();
            if(e!=-1)
                cout<< "���ӵĽ��ֵ�ǣ�"<<e<<endl;
            h.Display();
        }
        break;
        default:
            break;
        }
        cout<<"\n--------------------------------- ";
    }
    while(k>=1&&k<5);
    cout<<"\n          �ټ�!";
    cout<<"\n     ������������ء�";
    _getch();
    return 0;
}
