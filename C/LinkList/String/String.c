#include<stdio.h>
#include<malloc.h>
#include<string.h>

char *Create()
{
    int n;
    printf("Please input length of string \n");
    scanf("%d",&n);
    char *s;
    s = (char *)malloc(n*sizeof(char));
    printf("Please input string \n");
    scanf("%s",s);
    for(int i=0 ; i<n ;i++)
    {
        printf("%c",s[i]);
    }
    return s;
}

char *SubString (char *string,int pos,int len)
{
    int k = 0;
    char *subString_1;
    subString_1 = (char *)malloc(len*sizeof(char));
    for(int i=(pos-1) ; i<(pos+len-1) ;i++){
        subString_1[k] = string[pos-1];
    }
    return subString_1;
}

char *Insert(char *string, char *substring,int pos,int len)
{
    int a = strlen(string);
    char *string_1;
    string_1 = (char *)malloc((a+len)sizeof(char))
    strncoy(string_1,string,pos);
    strcat(string_1,substring);
    int j = p + strlen(substring);
    for(int i= pos ;i<strlen(string) ;i++ ;j++)
    {

        string_1[j] = string[i];
    }
    return string_1;

}

char *Delete(int pos,int num)
{

    return ;
}

void Print(char *s,int len)
{
    for(int i=0 ;i<len ;i++)
    {
        printf("%c",s[i]);

    }
}

int main()
{
    int i , pos , len;
    char *S,*subString_1,*subString_2;
    //printf("Please input a string : \n");

    do
        {
    printf("1. Create String \n");
    printf("2. Get Substring \n");
    printf("3. Insert Substring \n");
    printf("4. Delete Substring \n");
    printf("5. Exit");
    scanf("%d",&i);
            switch(i)
            {
                case 1:
                    S = Create();
                    len = strlen(S);
                    Print(S,len);
                    break;
                case 2:
                    printf("Please input position of substring: \n");
                    scanf("%d",&pos);
                    printf("Please input length of substring: \n");
                    scanf("%d",&len);
                    subString_1 = SubString(S,pos,len);
                    Print(subString_1,len);
                    /*for(int i=0 ;i<num; i++)
                    {
                        printf("%c",subString_1[i]);
                    }*/
                    break;
                case 3:
                    subString_2 = Create();
                    printf("Please input position of Inserted substring: \n");
                    scanf("%d",&pos);
                    printf("Please input length of Inserted substring: \n");
                    scanf("%d",&len);
                    S = Insert(S,subString_2,pos,len);
                    len = strlen(S);
                    Print(S,len);
                    break;
                case 4:
                    printf("Please input position of Deleted: \n");
                    scanf("%d",&pos);
                    printf("Please input length of Deleted substring: \n");
                    scanf("%d",&len);
                    S = Delete(pos,len);
                    S = strlen(S);
                    Print(S,len);
                    break;
                default:
                    break;
            }
        }while(i!= 5);
        return 0;
}

