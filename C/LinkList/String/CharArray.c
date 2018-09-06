#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char c[10];
    for(int i = 0; i<n; i++)
    {
        char c_1;
        scanf("%c",&c_1);
        c[i]=c_1;
    }
    for(int i = 0; i<n; i++)
    {
        printf("%c",c[i]);
    }
    return 0;
}
