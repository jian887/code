
#include<bits/stdc++.h>
using namespace std;
/*
#define inf 0x3f3f3f3f
#define ll long long
const int maxn=200005;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        scanf("%d %d",&n,&a);
        if(n>2||n==0)
        {
            printf("-1 -1\n");
        }
        else if(n==1)
        {
            printf("1 %d\n",a+1);
        }
        else if(n==2)
        {
            if(a%2)
            {
                n=(a-1)/2;
                printf("%d %d\n",n*n+(n+1)*(n+1)-1,n*n+(n+1)*(n+1));
            }
            else
            {
                n=a/2;
                printf("%d %d\n",n*n-1,n*n+1);
            }
        }
    }
    return 0;

}
