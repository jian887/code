#include<stdio.h>

int *fun()
{
    int *a,b;
    a=&b;
    b=1000;
    return a;
}

main()
{
    int *c;
    c = fun();
    printf("%d",c);

}
