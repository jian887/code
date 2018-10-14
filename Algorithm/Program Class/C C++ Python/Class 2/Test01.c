#include<stdio.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        int Y,n;
        scanf("%d %d",&Y,&n);
        while(n)
        {
            if((Y%4==0 && Y%100!=0) || (Y%400==0))
                n--;

            Y++;
        }
        printf("%d\n",Y-1);
    }
    return 0;
}

/*
´íÎóÊä³ö1
while(1)
        {
            if((Y%4==0 && Y%100!=0) || (Y%400==0))
            {
                y = Y+n*4;
                break;
            }
            else
            {
                Y+=1;
            }
        }
        printf("%d\n",y);



´íÎóÊä³ö2
while(n)
        {
            Y++;
            if((Y%4==0 && Y%100!=0) || (Y%400==0))
                n--;


        }
        printf("%d\n",Y);
3
2005 25
2108
1855 12
1904
2004 10000
43240


*/
