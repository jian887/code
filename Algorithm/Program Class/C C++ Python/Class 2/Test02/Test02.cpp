#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,a,b,c;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
            puts("good");//cout<<"good"<<endl;
        else if(a==b || a==c || b==c)
            cout<<"prefect"<<endl;
        else
            puts("just a triangle");//cout<<"just a triangle"<<endl;
    }
    return 0;
}
