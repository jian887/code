# include <stdio.h>
# include <malloc.h>

void f(int * q)
{
    *q = 200;
    //free(q);  //把q所指向的内存释放掉，不然后面在使用*p的时候会报错，因为p所指向的内容已经被释放了
}

int main(void)
{
    int * p = (int *)malloc(sizeof(int)); //sizeof(int)返回值是int所占的字节数
    *p = 10;
    f(p);  //p是int *类型
    printf("%d\n", *p);
    return 0;
}
