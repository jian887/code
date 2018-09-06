#include<iostream>                                                                                                                              
using namespace std;

struct MyNode
{
    MyNode(int a_data):m_data(a_data),m_pNext(NULL){}
    int m_data;
    MyNode *m_pNext;
};
class Josephus
{
    public:
        Josephus(int a_N,int a_K,int a_M):m_N(a_N),m_K(a_K),m_M(a_M){
            createList();
            outputList();
        }
    protected:
        void createList();
        void outputList();
    private:
        MyNode *m_pHead;   //循环链表的头节点
        int m_N;  //链表节点个数
        int m_K;  // 第一个报数人的序号
        int m_M;  // 报数出局的数
};
void Josephus::createList()
{
    MyNode *pre = NULL;
    MyNode *cur = NULL;
    MyNode *p = new MyNode(1);
    m_pHead = p;
    cur = p;
    for(int i=2; i<=m_N;i++)
    {
        p = new MyNode(i);
        pre = cur;
        cur = p;
        pre->m_pNext = p;
    }
    cur->m_pNext = m_pHead;
    int n = m_N;
    p = m_pHead;
    cout << "初始序列为:" << endl; 
    while(n--){
        cout << p->m_data << ",";
        p = p->m_pNext;
    }
    cout << endl;
}
void Josephus::outputList()
{
    // 让pStart指向第一个报数人的序号
    MyNode *pStart = m_pHead;  
    int count = 1;
    while(count < m_K){
        pStart = pStart->m_pNext;
        count++;
    }
    MyNode *pTemp = pStart;
    MyNode *pPre = NULL;
    MyNode *tobeDeleted = NULL;
    cout << "依次出局的序列为:" << endl;
    while(pTemp->m_pNext!=pTemp) // when pTemp->m_pNext==pTemp only one node in the list
    {
        int count = 1; 
        while(count < m_M){
            pPre = pTemp;
            pTemp = pTemp->m_pNext;
            count++;
        }
        tobeDeleted = pTemp;
        pTemp = pTemp->m_pNext;
        pPre->m_pNext = pTemp;
        cout << tobeDeleted->m_data << ",";
    }
    cout << pTemp->m_data << endl;
}

int main()
{
    int total_people;
    int start;
    int step;
    cout << "请输入总人数:" << endl;
    cin >> total_people;
    cout << "请输入开始数的人:" << endl;
    cin >> start;
    cout << "请输入出局人数的数:" << endl;
    cin >> step;
    Josephus josephus(total_people,start,step);
    return 0;
}