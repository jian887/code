#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d%d%d\n",n%100%10,n%100/10,n/100);
    // 123             =23 =3   =23 =2   =1
    printf("%d%d%d\n",n%10,n/10%10,n/100);
    // 123             =3   =12=2   =1
    return 0;
}

/*
�����������ʱ250�أ���ת052������52*/
