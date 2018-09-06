#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;

#define SIZE 20
struct QueuePoint
{
    char customer[20] ;
    int time;
    int time_2;
    struct QueuePoint *next;
};

struct Qu
{
    int length;
    int num;
};

class Queue
{
private:
    QueuePoint *head,*front_1,*rearOne;
    QueuePoint *head_2,*front_2,*rear_2;
    QueuePoint *head_3,*front_3,*rear_3;
//    QueuePoint *head_4,*front_4,rear_4;
//    QueuePoint *head_5,*front_5,rear_5;
    int length;
    Qu q[5];
public:
    Queue();
    ~Queue();
    void menu();
    void display();
    void inputQueue();
    void timing();
    int  insertQueueJudgement();
    void insertQueue(QueuePoint *pointOther);
    int getQueueLength(QueuePoint *pointHead);
    int ordering(int n);
    void outputQueueJudgement();
    int outputQueue_2(QueuePoint *pointHead,QueuePoint *TemporaryPoint);
    void  outputQueue(QueuePoint *pointHead);
    void delQueue();
};

Queue::Queue()
{
    front_1 = new QueuePoint[SIZE];
    front_2 = new QueuePoint[SIZE];
    front_3 = new QueuePoint[SIZE];

    rearOne = new QueuePoint[SIZE];
    rear_2 = new QueuePoint[SIZE];
    rear_3 = new QueuePoint[SIZE];
//    rear_4 = new QueuePoint[SIZE];
//    rear_5 = new QueuePoint[SIZE];
    head = new QueuePoint[SIZE];
    head_2 = new QueuePoint[SIZE];
    head_3 = new QueuePoint[SIZE];

    head->next = NULL;
    head_2->next = NULL;
    head_3->next = NULL;

    front_1->next = rearOne->next = head;
    front_2->next = rear_2->next = head_2;
    front_3->next = rear_3->next = head_3;
}

Queue::~Queue() {}

void Queue::menu()
{
    cout<<"1. չʾ����"<<endl;
    cout<<"2. �Ŷ�"<<endl;
    cout<<"3. ���"<<endl;
    cout<<"4. ���"<<endl;
    cout<<"5. �˳�����"<<endl;
    cout<<"��ע��(1).����ÿ������һ���˿��Ŷӣ���λ��min��"<<endl;
    cout<<"      (2).����6���ӿ�ѡ����ӻ��������Ŷӣ�"<<endl;
    cout<<"      (3).���ѿɲ�ӣ�������ʶ�Ĺ˿��������ɲ�ӵ����Ѻ��棻"<<endl;
    cout<<" ������ţ�"<<endl;
}

void Queue::display()
{
    QueuePoint *point;
    point = new QueuePoint[SIZE];
    point->next = NULL;
    int i = 0;
    point = head;
    cout<<"         "<<"����������ȴ�ʱ�䣬�ѵȴ�ʱ�䣩����������ȴ�ʱ�䣬�ѵȴ�ʱ�䣩����������ȴ�ʱ�䣬�ѵȴ�ʱ�䣩"<<endl;
    cout<<"��| ����1:";
    while(point->next != NULL)
    {
        point = point->next;
        cout<<point->customer<<setw(9)<<point->time<<"/min"<<setw(6)<<point->time_2<<"/min"<<setw(8)<<",";
    }
    cout<<endl;
    cout<<"��| ����2:";
    i = 0;
    point = head_2;
    while(point->next != NULL)
    {
        point = point->next;
        cout<<point->customer<<setw(9)<<point->time<<"/min"<<setw(6)<<point->time_2<<"/min"<<setw(8)<<",";
    }
    cout<<endl;
    cout<<"��| ����3:";
    i = 0;
    point = head_3;
    while(point->next != NULL)
    {
        point = point->next;
        cout<<point->customer<<setw(9)<<point->time<<"/min"<<setw(6)<<point->time_2<<"/min"<<setw(8)<<",";
    }
    cout<<endl;
    cout<<endl;
}

void Queue::inputQueue()
{

    char customer[20];
    int time_1;
    int s;

    QueuePoint *inputPoint;   //������ӵĹ˿�
    QueuePoint *TemporaryPoint;   //��ʱ���

    inputPoint = new QueuePoint[SIZE];
    inputPoint->next = NULL;
    TemporaryPoint= new QueuePoint[SIZE];
    TemporaryPoint->next = NULL;           //����ռ�
    srand((unsigned)time(NULL));
    cout<<"�Ŷ�"<<endl;
    cout<<"�˿ͣ�"<<endl;
    cin>>customer;
    time_1 = rand()%(10- 1) + 1;
    strcpy(inputPoint->customer,customer);
    inputPoint->time = time_1;
    cout<<""<<endl;
    cout<<"�ٴ�ȷ��:"<<endl;
    cout<<"�˿ͣ�"<<inputPoint->customer<<endl;
    cout<<"��ȴ�ʱ�䣺"<<inputPoint->time<<"/����"<<endl;
    //head->next = point;
    cout<<endl;
    q[0].length = getQueueLength(head);
    q[0].num = 1;

    q[1].length = getQueueLength(head_2);
    q[1].num = 2;
    q[2].length  = getQueueLength(head_3);
    q[2].num = 3;
//    for(int j = 0; j<3 ; j++)
//    {
//        cout<<q[j].length<<"  "<<q[j].num<<endl;
//    }
    if (q[0].length==q[1].length&&q[1].length==q[2].length)
    {
        srand((unsigned)time(NULL));
        s = rand()%(4- 1) + 1;
        cout<<"����ŶӶӺţ�"<<s<<endl;
    }
    else
    {
        s = ordering(3);
        cout<<"��̶���Ӻţ�"<<s<<endl;
    }

    switch(s)
    {
    case 1:
        TemporaryPoint = rearOne->next;
        TemporaryPoint->next = inputPoint;
        rearOne->next = inputPoint;
        break;
    case 2:
        TemporaryPoint = rear_2->next;
        TemporaryPoint->next = inputPoint;
        rear_2->next = inputPoint;
        break;
    case 3:
        TemporaryPoint = rear_3->next;
        TemporaryPoint->next = inputPoint;
        rear_3->next = inputPoint;
        break;
    case 4:
        break;
    case 5:
        break;
    }
    //cout<<"�˿�"<<head->next->customer<<endl;
    cout<<endl;
    display();
}

void Queue::timing()
{
    QueuePoint *point,*point_2,*point_3;
    point = new QueuePoint[SIZE];
   // point->next = NULL;
    point_2 = new QueuePoint[SIZE];
   // point_2->next = NULL;
    point_3 = new QueuePoint[SIZE];
   // point_3->next = NULL;
    cout<<"���"<<endl;

    point->time--;
        point_2->time--;
        point_3->time--;

//    if(head->next!=NULL && head_2->next!=NULL && head_3->next!=NULL)
//    {
//            point = head->next;
//    point_2 = head_2->next;
//    point_3 = head_3->next;
//        point->time--;
//        point_2->time--;
//        point_3->time--;
//    }
//    else if(head->next!=NULL && head_2->next!=NULL)
//    {
//        point->time--;
//        point_2->time--;
//    }
//    else if(head_2->next!=NULL && head_3->next!=NULL)
//    {
//        point_2->time--;
//        point_3->time--;
//    }
//    else if(head->next!=NULL &&  head_2->next!=NULL)
//    {
//        point->time--;
//        point_3->time--;
//    }
//    else if(head->next!=NULL)
//    {
//        point = head->next;
//        cout<<1<<endl;
//        cout<<point->time--;
//
//    }
//    else if( head_2->next!=NULL)
//    {
//        point_2 = head->next;
//        cout<<2<<endl;
//        cout<<point_2->time--;
//
//    }
//    else if(head_3->next!=NULL)
//    {
//        point_3 = head->next;
//        cout<<3<<endl;
//        cout<<point_3->time;
//
//    }

   // goto a;
//    else{
//        return 0;
//    }

//    if((point->time!=NULL) && (point_2->time!=NULL) && (point_3->time!=NULL))
//    {
//        point->time--;
//        point_2->time--;
//        point_3->time--;
//    }
//    else if(point->time!=NULL && point_2->time!=NULL)
//    {
//         point->time--;
//        point_2->time--;
//    }
//    else if(point_2->time!=NULL &&  point_3->time!=NULL)
//    {
//          point_2->time--;
//        point_3->time--;
//    }
//    else if(point->time!=NULL && point_3->time!=NULL)
//    {
//       point->time--;
//         point_3->time--;
//    }
//    else if(point->time!=NULL)
//    {
//       point->time--;
//    }
//    else if(point_2->time!=NULL)
//    {
//        cout<<2<<endl;
//       point_2->time--;
//    }
//    else if(point_3->time!=0)
//    {
//        cout<<3<<endl;
//        point_3->time--;
//    }
//    else{
//        return 0;
//    }
    if(point->time==0 && point_2->time==0 && point_3->time==0)
    {
        outputQueue(head);
        outputQueue(head_2);
        outputQueue(head_3);
    }
    else if(point->time==0 && point_2->time==0)
    {
        outputQueue(head);
        outputQueue(head_2);
    }
    else if(point_2->time==0 &&  point_3->time==0)
    {
        outputQueue(head_2);
        outputQueue(head_3);
    }
    else if(point->time==0 && point_3->time==0)
    {
        outputQueue(head);
        outputQueue(head_3);
    }
    else if(point->time==0)
    {
        cout<<1<<endl;
        outputQueue(head);
    }
    else if(point_2->time==0)
    {
        cout<<2<<endl;
        outputQueue(head_2);
    }
    else if(point_3->time==0)
    {
        cout<<3<<endl;
        outputQueue(head_3);
    }
    display();

}

void Queue::outputQueue(QueuePoint *pointHead)
{
    QueuePoint *point,*TemporaryPoint;
    cout<<"���"<<endl;
    point = pointHead;
    if(point->next==NULL)
    {
        cout<<"�����ѿ�"<<endl;

    }
    else
    {
        TemporaryPoint = point->next;
        point->next = TemporaryPoint->next;
    }
    cout<<endl;
    display();
}

int Queue::insertQueueJudgement()
{
    QueuePoint *point,*friendPoint,*TemporaryPoint;
    QueuePoint *point_2,*point_3;
    char customer_1 [20];
    char customer_2 [20];
    int time_2;
    int a;
    point = new QueuePoint[SIZE];
    point->next = NULL;
    cout<<"�����������ѵ�������"<<endl;
    cin>>customer_1;
    point = head;
    point_2 = head_2;
    point_3 = head_3;
    while(point->next != NULL)
    {
        point = point->next;
        //cout<<point->customer<<endl;
        if(strcmp(point->customer,customer_1)== 0)
        {
            a = 0;
            insertQueue(point);
            return 0;
        }
    }
    while(point_2->next != NULL)
    {
        point_2 = point_2->next;
        //cout<<point_2->customer<<endl;
        if(strcmp(point_2->customer,customer_1)== 0)
        {
            a = 0;
            insertQueue(point_2);
            return 0;
        }
    }
    while(point_3->next != NULL)
    {
        point_3 = point_3->next;
        // cout<<point_3->customer<<endl;
        if(strcmp(point_3->customer,customer_1)== 0)
        {
            a = 0;
            insertQueue(point_3);
            return 0;
        }
    }
    cout<<"�Բ��𣬶�����û��������ѣ��밴�����������Ŷ�"<<endl;
    inputQueue();
    display();
}

void Queue::outputQueueJudgement()
{
    QueuePoint *point,*TemporaryPoint;
    point = new QueuePoint[SIZE];
    point->next = NULL;
    TemporaryPoint = new QueuePoint[SIZE];
    TemporaryPoint->next = NULL;
    int i = 0;
    point = head;
    //cout<<"����1"<<endl;
    while(point->next != NULL)
    {
        TemporaryPoint = point;
        point = point->next;
        point->time_2++;
        if(point->time_2==6)
        {
            outputQueue_2(point,TemporaryPoint);
        }
    }
    //cout<<endl;
    // cout<<"����2"<<endl;
    i = 0;
    point = head_2;
    while(point->next != NULL)
    {
        TemporaryPoint = point;
        point = point->next;
        point->time_2++;
        if(point->time_2==6)
        {
            outputQueue_2(point,TemporaryPoint);
        }
    }
    // cout<<endl;
    // cout<<"����3"<<endl;
    i = 0;
    point = head_3;
    while(point->next != NULL)
    {
        TemporaryPoint = point;
        point = point->next;
        point->time_2++;
        if(point->time_2==6)
        {
            outputQueue_2(point,TemporaryPoint);
        }
    }
    cout<<endl;
}

int Queue::outputQueue_2(QueuePoint *pointHead,QueuePoint *TemporaryPoint)
{
    QueuePoint *point;

    int i,j;
    cout<<"����ӹ˿ͣ�"<<endl;
    cout<<pointHead->customer<<" "<<pointHead->time<<"/min"<<pointHead->time_2<<"/min"<<endl;
    cout<<endl;
    cout<<"���ȴ�ʱ���Ѿ�����1���ӣ��Ƿ���ӣ�"<<endl;
    cout<<"1. ����"<<endl;
    cout<<"2. ���"<<endl;
    cin>>i;
    switch(i)
    {
    case 1:
        return 0;
    case 2:
    {
//        if(TemporaryPoint->customer== NULL){
//            TemporaryPoint->
//        }
//        else

        point = pointHead->next;
        TemporaryPoint->next = point;
        //pointHead =  pointHead->next;



        display();
        cout<<"���Ѿ���ӣ��Ƿ������Ŷ�"<<endl;
        cout<<"1. �������Ŷ�"<<endl;
        cout<<"2. �����Ŷ� "<<endl;
        cin>>j;
        switch(j)
        {
        case 1:
            return 0;
        case 2:
            inputQueue();
            break;
        default:
            cout<<"�����������������"<<endl;
        }
    }
    break;
    }
}

void Queue::insertQueue(QueuePoint *pointOther)
{

    QueuePoint *point,*friendPoint,*TemporaryPoint;
    point = pointOther;
    srand((unsigned)time(NULL));

    friendPoint = new QueuePoint[SIZE];
    friendPoint->next = NULL;
    TemporaryPoint = new QueuePoint[SIZE];
    TemporaryPoint->next = NULL;
    char customer_1 [20];
    int time_1 = rand()%(4- 1) + 1;;

    cout<<"�˿ͣ�"<<endl;
    cin>>customer_1;
    cout<<"ʱ�䣺"<<"/min"<<endl;
    time_1 = rand()%(4- 1) + 1;;
    strcpy(friendPoint->customer,customer_1);
    friendPoint->time = time_1;
    cout<<""<<endl;
    cout<<"�ٴ�ȷ��"<<endl;
    cout<<"�˿ͣ�"<<friendPoint->customer<<endl;
    cout<<"ʱ�䣺"<<friendPoint->time<<"/min"<<endl;

    TemporaryPoint = point->next;
    point->next = friendPoint;
    friendPoint->next = TemporaryPoint;
    cout<<endl;
    display();
}

int Queue::getQueueLength(QueuePoint *pointHead)
{
    QueuePoint *point;
    point = new QueuePoint[SIZE];
    point->next = NULL;
    int length = 0;
    if(pointHead->next==NULL)
    {
        return length = 0;
    }
    else
    {
        point = pointHead;
        while(point->next != NULL)
        {
            length++;
            point = point->next;
        }
        return length;
    }
}

int Queue::ordering(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n+1; j++)
        {
            if (q[i].length>q[j].length)
            {
                int temp_1 = q[i].length;
                q[i].length = q[j].length;
                q[j].length = temp_1;
                int temp_2 = q[i].num;
                q[i].num = q[j].num;
                q[j].num = temp_2;
            }
            //ÿ��i�����Ԫ�ر�length[i]С�ͽ�����
        }
    }
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"���鳤�ȣ�"<<q[i].length<<" ,"<<"������ţ�"<<q[i].num<<";"<<endl;

    }
    return q[0].num;
}

int main()
{
    Queue q;
    int c,l;
    a: while(true)
    {
        q.menu();
        cin>>c;
        switch(c)
        {
        case 1:
            q.display();
            break;
        case 2:
            q.inputQueue();
            q.outputQueueJudgement();
           // q.timing();
            break;
        case 3:
            q.timing();
            break;
        case 4:
            q.insertQueueJudgement();
            break;
        case 5:
            return 0;
            break;
        default:
            cout<<"�������Ų��ԣ�����������"<<endl;
        }
    }
    return 0;
}




