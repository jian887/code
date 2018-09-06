#include<stdio.h>
#include<malloc.h>

int main()
{
    int n;
    scanf("%d",&n);
    char *c;
    c = (char *)malloc(n*sizeof(char));
    scanf("%s",c);
    for(int i=0 ; i<n ;i++)
    {
        printf("%c",c[i]);

    }
    return 0;
}
