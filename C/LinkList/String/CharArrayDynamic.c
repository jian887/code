#include<stdio.h>
#include<malloc.h>
int main()
{
    int n;
    scanf("%d",&n);
    char *arr;
    arr = (char *)malloc (n*sizeof(char));
    for (char i=0 ; i<n ;i++){
        arr[i] = 'ew';
        printf("%c\n",arr[i]);
    }


}

