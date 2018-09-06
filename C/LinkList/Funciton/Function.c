#include<stdio.h>

void fun(int a)
{
    a = 2;
    printf("%d",a);
}

int main()
{

    int i;
    fun(i);
    return 0;
}
