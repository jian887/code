#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,b,c;
    int i,j;
    cin >> t;
    for(i = 0; i<t; i++)
    {
        scanf("%d %d",&n,&a);
        if(n==0)
        {
            printf("-1 -1\n");
        }
        else if(n==1)
        {
            printf("1 %d\n",a+1);
        }
        else if(n==2)
        {
            if(a%2==0)
            {
                n=a/2;
                b = n*n-1;
                c = n*n+1;

            }
            else
            {

                n=(a-1)/2;
                b = n*n+(n+1)*(n+1)-1;
                c = n*n+(n+1)*(n+1);

            }
            printf("%d %d\n",b,c);
        }
        else
        {
            printf("-1 -1\n");
        }
    }
    return 0;
}
