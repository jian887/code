#include<stdio.h>

int gougu(int a,int b,int c)
{

    int s;
    if(a*a+b*b==c*c)
    {
        s = 0;
        return s;
    }
    else
    {
        s = 1;
        return s;
    }
}

int main()
{
    int i;
    int t,a,b,c;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(gougu(a,b,c)==0||gougu(b,a,c)||(c,a,b)){

        }
        }

}
