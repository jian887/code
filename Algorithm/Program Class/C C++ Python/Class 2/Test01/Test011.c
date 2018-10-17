#include<stdio.h>
int main()
{
   int N,x,y,i;
   scanf("%d",&N);
   for(i=0;i<N;i++)
   {
       scanf("%d %d",&x,&y);
       while(y)
       {
           if((x%4==0&&x%100!=0)||x%400==0)
                 y--;
           x++;
       }
       printf("%d\n",x-1);
   }
   return 0;
}
