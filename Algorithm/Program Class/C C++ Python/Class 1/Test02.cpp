#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a,b;
    while(true)
    {
        cin >> a >> b;
        if(kbhit())
        {break;}
        cout<< a + b <<endl;
    }
    return 0;
}
