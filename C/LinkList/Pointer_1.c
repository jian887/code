#include<stdio.h>

int main()
{
    int *pinter_1;
    int var;
    pinter_1 = &var;

    printf("%p\n",&var);
    printf("%p\n",pinter_1);
    printf("%d\n",*pinter_1);

    var = 1;

    printf("%p\n",pinter_1);
    printf("%d\n",*pinter_1);

    *pinter_1 = 2;

    printf("%p\n",pinter_1);
    printf("%d\n",*pinter_1);

}
