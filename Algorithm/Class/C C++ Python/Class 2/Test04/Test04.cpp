#include<iostream>
using namespace std;
int main()
{
    int n,m,r;
    while(cin>>n>>m,(n!=-1||m!=-1))
    {
        while(m!=0)//Õ·×ªÏà³ý
        {
            r=n%m;
            n=m;
            m=r;
        }
        if(n==1)
            cout<<"YES"<<endl;
        else
            cout<<"POOR Haha"<<endl;
    }
    return 0;
}
