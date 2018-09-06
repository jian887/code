#include<stdio.h>
#include<malloc.h>
int main()
{
    int *pointer_1,*pointer_2;
    int var;
    pointer_1 = &var;
    pointer_2=pointer_1;

    printf("%p\n",&var);
    printf("%p\n",pointer_1);
    printf("%p\n",pointer_2);

    int *pointer_3;
    pointer_3 = (int *)malloc(sizeof(int));
    printf("%p\n",pointer_3);
    return 0;
}
