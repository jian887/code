# include <stdio.h>
# include <malloc.h>

void f(int * q)
{
    *q = 200;
    //free(q);  //��q��ָ����ڴ��ͷŵ�����Ȼ������ʹ��*p��ʱ��ᱨ����Ϊp��ָ��������Ѿ����ͷ���
}

int main(void)
{
    int * p = (int *)malloc(sizeof(int)); //sizeof(int)����ֵ��int��ռ���ֽ���
    *p = 10;
    f(p);  //p��int *����
    printf("%d\n", *p);
    return 0;
}
