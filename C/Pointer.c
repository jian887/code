#include<stdio.h>

main()
{
    int var = 20;
    int var_1[100];
    printf("%p  ,  %p \n",&var,&var_1);  //一般变量的内存地址
    printf("%x  ,  %x \n",&var,&var_1);
    printf("%d  ,  %d \n",&var,&var_1);
    int *pointer=NULL;
    printf("%p",pointer);
}
