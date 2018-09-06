#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
const int MaxVertices=10;
const int MaxWeight=10000;
struct MinSpanTree              //��Ȩ�ߵ���������
{
    int begin,end;              //�ߵ�������յ�
    float length;                 //�ߵ�Ȩֵ
};
class  AdjMWGraph
{
private:
    int  Vertices[10];                     //������Ϣ������
    int  Edge[MaxVertices][MaxVertices];   //�ߵ�Ȩ��Ϣ�ľ���
    int  numE;                             //��ǰ�ı���
    int  numV;                             //��ǰ�Ķ�����
public:
    AdjMWGraph();      				//���캯��
    void  CreatG(int n,int e);
    void  PrintOut();
    void  Prim() ;						//����С����������
};
AdjMWGraph::AdjMWGraph()        //���캯��
{
    for ( int i=0; i<MaxVertices; i++ )
        for ( int j=0; j<MaxVertices; j++ )
        {
            if( i==j )
                Edge[i][j]=0;
            else
                Edge[i][j]=MaxWeight; //MaxWeight��ʾ�����
        }
    numE=0;                         //��ǰ�߸�����ʼΪ0
    numV=0;
}
void  AdjMWGraph::CreatG(int n,int e)
{
    int vi,vj,w;
    numE=e;
    numV=n;
    cout<<"\n  ���붥�����Ϣ�����ͣ���" ;
    for (int i=0; i<numV; i++ )
    {
        cout<<"\n "<<i+1<<": ";
        cin>>Vertices[i];
    }
    for ( int i=0; i<numE; i++ )
    {
        cout<<"\n  ����ߵ���Ϣ��vi,vj,W����";
        cin>>vi>>vj>>w;
        Edge[vi-1][vj-1]=w;
        Edge[vj-1][vi-1]=w;   //��������ͼ
    }
}
void AdjMWGraph::PrintOut()
{
    cout<<"\n  ����������Ϣ�����ͣ���\n";
    for ( int i=0; i<numV; i++ )
        cout<<Vertices[i]<<"  ";
    cout<<"\n  ����ڽӾ��� ��" ;
    for (int i=0; i<numV; i++ )
    {
        cout<<"\n "<<i+1<<": ";
        for ( int j=0; j<numV ; j++ )
            cout<<Edge[i][j]<<"  ";
        cout<<endl;
    }
}
void  AdjMWGraph::Prim ()
{
    int low[MaxVertices];
    int aj[MaxVertices];
    for (int i=0 ; i<MaxVertices ; i++)
    {
        low[i] = Edge[0][i];
        aj[i] = 0;
    }
    for (int i=1 ; i<MaxVertices ; i++)
    {

        int j=1,k=0;
        int Min = 32767;
        while(j<MaxVertices)
        {
            if (low[j]!=0 && low[j]<Min)
            {
                Min = low[j];
                k = j;
            }
            j++;
        }

        cout<<"\n"<<"�ߣ�("<<aj[k]<<","<<k<<")";
        low [k] = 0;
        for(int j=i ; j<MaxVertices ; j++)
        {
            if (low[j]>0 && low[j]>Edge[k][j]) {}
            low[j] = Edge[k][j];
            aj[j] = k ;
        }
    }
    for(int i=0 ; i<MaxVertices ; i++)
    {
        cout<<aj[i]<<endl;
    }
}
int main(int argc, char* argv[])
{
    AdjMWGraph  G ;
    int n,e;
    cout<<"\n  ������ͼ���ܶ��������ܱ�����n,e=?����";
    cin>>n>>e ;
    G.CreatG(n,e);
    G.PrintOut();
    cout<<"��С����������";
    cout<<"����"<<n-1<<"����" ;

    G.Prim();
    //_getch();
    return 0;
}




/*
  A  B  C  D  E  F
A 0  34 46 0  0  19
B 34
*/
