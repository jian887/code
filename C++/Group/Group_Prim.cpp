#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
const int MaxVertices=10;
const int MaxWeight=10000;
struct MinSpanTree              //带权边的三个参数
{
    int begin,end;              //边的起点与终点
    float length;                 //边的权值
};
class  AdjMWGraph
{
private:
    int  Vertices[10];                     //顶点信息的数组
    int  Edge[MaxVertices][MaxVertices];   //边的权信息的矩阵
    int  numE;                             //当前的边数
    int  numV;                             //当前的顶点数
public:
    AdjMWGraph();      				//构造函数
    void  CreatG(int n,int e);
    void  PrintOut();
    void  Prim() ;						//求最小生成树方法
};
AdjMWGraph::AdjMWGraph()        //构造函数
{
    for ( int i=0; i<MaxVertices; i++ )
        for ( int j=0; j<MaxVertices; j++ )
        {
            if( i==j )
                Edge[i][j]=0;
            else
                Edge[i][j]=MaxWeight; //MaxWeight表示无穷大
        }
    numE=0;                         //当前边个数初始为0
    numV=0;
}
void  AdjMWGraph::CreatG(int n,int e)
{
    int vi,vj,w;
    numE=e;
    numV=n;
    cout<<"\n  输入顶点的信息（整型）：" ;
    for (int i=0; i<numV; i++ )
    {
        cout<<"\n "<<i+1<<": ";
        cin>>Vertices[i];
    }
    for ( int i=0; i<numE; i++ )
    {
        cout<<"\n  输入边的信息（vi,vj,W）：";
        cin>>vi>>vj>>w;
        Edge[vi-1][vj-1]=w;
        Edge[vj-1][vi-1]=w;   //对于无向图
    }
}
void AdjMWGraph::PrintOut()
{
    cout<<"\n  输出顶点的信息（整型）：\n";
    for ( int i=0; i<numV; i++ )
        cout<<Vertices[i]<<"  ";
    cout<<"\n  输出邻接矩阵 ：" ;
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

        cout<<"\n"<<"边：("<<aj[k]<<","<<k<<")";
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
    cout<<"\n  请输入图的总顶点数和总边数（n,e=?）：";
    cin>>n>>e ;
    G.CreatG(n,e);
    G.PrintOut();
    cout<<"最小生成树如下";
    cout<<"共有"<<n-1<<"条边" ;

    G.Prim();
    //_getch();
    return 0;
}




/*
  A  B  C  D  E  F
A 0  34 46 0  0  19
B 34
*/
