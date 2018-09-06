#include<iostream>



#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int r[10];
    for(int i=0 ;i<10 ;i++)
    {
        r[i] = rand()%(6- 1) + 1;
    }
      for(int i=0 ;i<10 ;i++)
    {
        cout<<r[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
     for(int i=0 ;i<10 ;i++)
    {
        r[i] = rand()%(1 - 5 + 1) + 5;
    }
     for(int i=0 ;i<10 ;i++)
    {
        cout<<r[i]<<endl;
    }


}
