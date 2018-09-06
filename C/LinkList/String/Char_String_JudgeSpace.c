#include<stdio.h>

int main()
{
    char c;
    int result = 0;

    while(scanf("%c",&c))
    {
                    if(c=='\n')//输入用换行符结束
                               break;
                    if(isalpha(c))//判断是否为字母字符
                    {
                                  result++;
                    }
    }
    printf("%d",result);
}
