#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char c_1[10] = "232254";
    char c_2[10] = "232254";
    int a;
    if(c_1==c_2) a = 0;
    else a = 1;
    cout<<a<<endl;
    a = strcmp(c_1,c_2);
    if(a==0) a = 0;
    else a = 1;
    cout<<a<<endl;
    if(strcmp(c_1,c_2)==0) cout<<a<<endl;

}
