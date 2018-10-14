#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d",&n);
    m = n%10*100+n/10%10*10+n/100;
    printf("%d\n",m);
    printf("%01d\n",m);
    printf("%02d\n",m);
    printf("%03d\n",m);
    printf("%04d\n",m);
    return 0;
}

/*
但是如果输入时250呢，反转052，还是52*/
