
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

using namespace std;

#define SIZE 20
#define TIME 6

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
public:
    QueuePoint *head,*front_1,*rearOne;
    QueuePoint *head_2,*front_2,*rear_2;
    QueuePoint *head_3,*front_3,*rear_3;
    int length;
    Qu q[5];
public:
    Queue();                                      //初始化队列
    ~Queue();
    void menu();                                  //菜单栏
    void display();                               //展示队列
    void inputQueue();                            //入队

    int getQueueLength(QueuePoint *pointHead);   //获取队列长度
    int ordering(int n);                         //队列排序

    void timing();                               //计算交易时间
    void  outputQueue_1(QueuePoint *pointHead);    //交易完成离队（交易时间为零）

    void outputQueueJudgement();                 //计算等待时间
    int outputQueue_2(QueuePoint *pointHead,QueuePoint *TemporaryPoint);   //等待时间超时，离队


    int  insertQueueJudgement();                  //通过查找姓名的方式查找其朋友
    void insertQueue(QueuePoint *pointOther);     //朋友插队


};

Queue::Queue()
{
    rearOne = new QueuePoint[SIZE];
    rear_2 = new QueuePoint[SIZE];
    rear_3 = new QueuePoint[SIZE];

    head = new QueuePoint[SIZE];
    head_2 = new QueuePoint[SIZE];
    head_3 = new QueuePoint[SIZE];

    head->next = NULL;
    head_2->next = NULL;
    head_3->next = NULL;

   rearOne->next = head;
    rear_2->next = head_2;
    rear_3->next = head_3;
}

Queue::~Queue() {}

void Queue::menu()
{
    cout<<"1. 展示队列"<<endl;
    cout<<"2. 排队"<<endl;
    cout<<"3. 朋友插队"<<endl;
    cout<<"4. 退出程序"<<endl;
    cout<<"（注：(1).假设每分钟有一名顾客排队，单位：min；"<<endl;
    cout<<"      (2).超过6分钟可选择离队或者重新排队；"<<endl;
    cout<<"      (3).朋友可插队，输入认识的顾客姓名，可插队到朋友后面；"<<endl;
    cout<<" 输入序号："<<endl;
}

void Queue::display()
{
    QueuePoint *point;
    point = new QueuePoint[SIZE];
    point->next = NULL;
    int i = 0;
    point = head;
    cout<<"         "<<"（姓名，需等待时间，已等待时间）（姓名，需等待时间，已等待时间）（姓名，需等待时间，已等待时间）"<<endl;
    cout<<"杂| 队伍1:";
    while(point->next != NULL)
    {
        point = point->next;
        cout<<point->customer<<setw(9)<<point->time<<"/min"<<setw(6)<<point->time_2<<"/min"<<setw(8)<<",";
    }
    cout<<endl;
    cout<<"货| 队伍2:";
    i = 0;
    point = head_2;
    while(point->next != NULL)
    {
        point = point->next;
        cout<<point->customer<<setw(9)<<point->time<<"/min"<<setw(6)<<point->time_2<<"/min"<<setw(8)<<",";
    }
    cout<<endl;
    cout<<"店| 队伍3:";
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

    QueuePoint *inputPoint;   //接收入队的顾客
    QueuePoint *TemporaryPoint;   //临时结点

    inputPoint = new QueuePoint[SIZE];
    inputPoint->next = NULL;
    TemporaryPoint= new QueuePoint[SIZE];
    TemporaryPoint->next = NULL;           //赋予空间
    srand((unsigned)time(NULL));
    cout<<"排队"<<endl;
    cout<<"顾客："<<endl;
    cin>>customer;
    time_1 = rand()%(10- 1) + 3;
    strcpy(inputPoint->customer,customer);
    inputPoint->time = time_1;
    cout<<""<<endl;
    cout<<"再次确认:"<<endl;
    cout<<"顾客："<<inputPoint->customer<<endl;
    cout<<"需等待时间："<<inputPoint->time<<"/分钟"<<endl;
    //head->next = point;2
    cout<<endl;
    q[0].length = getQueueLength(head);
    q[0].num = 1;

    q[1].length = getQueueLength(head_2);
    q[1].num = 2;
    q[2].length  = getQueueLength(head_3);
    q[2].num = 3;

    if (q[0].length==q[1].length&&q[1].length==q[2].length)
    {
        srand((unsigned)time(NULL));
        s = rand()%(4- 1) + 1;
        cout<<"随机排队队号："<<s<<endl;
    }
    else
    {
        s = ordering(3);
        cout<<"最短队伍队号："<<s<<endl;
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
        }
    }
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"队伍长度："<<q[i].length<<" ,"<<"队伍序号："<<q[i].num<<";"<<endl;
    }
    return q[0].num;
}



void Queue::timing()
{
    QueuePoint *point,*point_2,*point_3;
    point = new QueuePoint[SIZE];
    point_2 = new QueuePoint[SIZE];
    point_3 = new QueuePoint[SIZE];

    point = head->next;
    point_2 = head_2->next;
    point_3 = head_3->next;

    point->time--;
    point_2->time--;
    point_3->time--;

    if(point->time==0 && point_2->time==0 && point_3->time==0)
    {
        outputQueue_1(head);
        outputQueue_1(head_2);
        outputQueue_1(head_3);
    }
    else if(point->time==0 && point_2->time==0)
    {
        outputQueue_1(head);
        outputQueue_1(head_2);
    }
    else if(point_2->time==0 &&  point_3->time==0)
    {
        outputQueue_1(head_2);
        outputQueue_1(head_3);
    }
    else if(point->time==0 && point_3->time==0)
    {
        outputQueue_1(head);
        outputQueue_1(head_3);
    }
    else if(point->time==0)
    {
        cout<<1<<endl;
        outputQueue_1(head);
    }
    else if(point_2->time==0)
    {
        cout<<2<<endl;
        outputQueue_1(head_2);
    }
    else if(point_3->time==0)
    {
        cout<<3<<endl;
        outputQueue_1(head_3);
    }
    display();

}

void Queue::outputQueue_1(QueuePoint *pointHead)
{
    QueuePoint *point,*TemporaryPoint;
    cout<<"交易已完成。"<<endl;
    cout<<"顾客"<<pointHead->next->customer<<"已离队。"<<endl;
    point = pointHead;
    if(point->next==NULL)
    {
        cout<<"队列已空"<<endl;
    }
    else
    {
        TemporaryPoint = point->next;
        point->next = TemporaryPoint->next;
    }
    cout<<endl;
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
    while(point->next != NULL)
    {
        TemporaryPoint = point;
        point = point->next;
        point->time_2++;
        if(point->time_2==TIME)
        {
            outputQueue_2(point,TemporaryPoint);
        }
    }

    i = 0;
    point = head_2;
    while(point->next != NULL)
    {
        TemporaryPoint = point;
        point = point->next;
        point->time_2++;
        if(point->time_2==TIME)
        {
            outputQueue_2(point,TemporaryPoint);
        }
    }
    i = 0;
    point = head_3;
    while(point->next != NULL)
    {
        TemporaryPoint = point;
        point = point->next;
        point->time_2++;
        if(point->time_2==TIME)
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
    cout<<"可离队顾客："<<endl;
    cout<<pointHead->customer<<" ,需等待时间："<<pointHead->time<<"/min"<<" ,已等待时间："<<pointHead->time_2<<"/min"<<endl;
    cout<<endl;
    cout<<"顾客"<<pointHead->customer<<"，您等待时间已经超过1分钟，是否离队，"<<endl;
    cout<<"1. 留队"<<endl;
    cout<<"2. 离队"<<endl;
    cout<<"请输入相应号码："<<endl;
    cin>>i;
    switch(i)
    {
    case 1:
        return 0;
    case 2:
    {
        point = pointHead->next;
        TemporaryPoint->next = point;
        display();
        cout<<"您已经离队，是否重新排队"<<endl;
        cout<<"1. 不重新排队"<<endl;
        cout<<"2. 重新排队 "<<endl;
        cout<<"请输入相应号码："<<endl;
        cin>>j;
        switch(j)
        {
        case 1:
            return 0;
        case 2:
            inputQueue();
            break;
        default:
            cout<<"输入错误，请重新来过"<<endl;
        }
    }
    break;
    }
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
    cout<<"请输入你朋友的姓名："<<endl;
    cin>>customer_1;
    point = head;
    point_2 = head_2;
    point_3 = head_3;
    while(point->next != NULL)
    {
        point = point->next;
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
        if(strcmp(point_3->customer,customer_1)== 0)
        {
            a = 0;
            insertQueue(point_3);
            return 0;
        }
    }
    cout<<"对不起，队伍中没有你的朋友，请按照正常秩序排队"<<endl;
    inputQueue();
    display();
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

    cout<<"顾客："<<endl;
    cin>>customer_1;
    cout<<"时间："<<"/min"<<endl;
    time_1 = rand()%(4- 1) + 1;;
    strcpy(friendPoint->customer,customer_1);
    friendPoint->time = time_1;
    cout<<""<<endl;
    cout<<"再次确认"<<endl;
    cout<<"顾客："<<friendPoint->customer<<endl;
    cout<<"时间："<<friendPoint->time<<"/min"<<endl;

    TemporaryPoint = point->next;
    point->next = friendPoint;
    friendPoint->next = TemporaryPoint;
    cout<<endl;
    display();
}

int main()
{
    Queue q;
    int c,l;
    while(true)
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
            if((q.head->next!=NULL && q.head_2->next!=NULL)&&(q.head->next!=NULL && q.head_3!=NULL) &&(q.head_2->next!=NULL && q.head_3!=NULL) )
            {
                q.timing();
            }
            break;
        case 3:
           q.insertQueueJudgement();
            break;
        case 4:
            return 0;
            break;
        default:
            cout<<"输入的序号不对，请重新输入"<<endl;
        }
    }
    return 0;
}



