#include<stdio.h>

int main()
{
    char c;
    int result = 0;

    while(scanf("%c",&c))
    {
                    if(c=='\n')//�����û��з�����
                               break;
                    if(isalpha(c))//�ж��Ƿ�Ϊ��ĸ�ַ�
                    {
                                  result++;
                    }
    }
    printf("%d",result);
}
