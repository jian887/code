#include<stdio.h>
#include<malloc.h>
int main()
{
    char *p;

    p=(char *)malloc(100);
    if(p)
        printf("Memory Allocated at: %x/n",p);
    else
        printf("Not Enough Memory!/n");
    free(p);
    return 0;
}
