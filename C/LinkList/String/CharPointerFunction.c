#include<stdio.h>
#include<malloc.h>

char *fun(char *s)
{
    s = (char *)malloc(4*sizeof(char));
    scanf("%s",s);
    for(int i = 0 ;i<4 ;i++){
        printf("%c",s[i]);
    }
    return s;
}

int main()
{

    char *c;
}
