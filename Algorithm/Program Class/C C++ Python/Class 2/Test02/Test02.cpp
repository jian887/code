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
            cout<<"good"<<endl;
        else if(a==b || a==c || b==c)
            cout<<"perfect"<<endl;
        else
            puts("just a triangle");  //AC
            //cout<<"just a triangle"<<endl; Wrong Answer
    }
    return 0;
}
