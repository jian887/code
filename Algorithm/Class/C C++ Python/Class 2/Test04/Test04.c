#include <stdio.h>

int main()
{
   int m ,n,temp;
   while(scanf("%d %d",&m,&n),m + n != -2) {

        while(n!=0){
            temp = m%n;
            m = n;
            n = temp;
        }
        if(m==1)
            printf("YES\n");
        else
            printf("POOR Haha\n");
   }
   return 0;
}
