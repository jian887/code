#include <iostream>
using namespace std;

int main()
{
    int intput = 2991;

    while(intput/10000==0)
    {
        intput++;
        int sum = intput/1000 + intput/100%10 + intput%100/10 +intput%10;
        int value = intput;
        int sum_o = 0;

        while(value)
        {
            sum_o += value % 12;

            value = value /12;
        }
       // cout<<"12 "<<sum_o<<" "<<sum<<endl;
        if(sum_o != sum)
            continue;
        sum_o = 0;
        value = intput;
        while(value)
        {
            sum_o += value % 16;
            value = value /16;
        }
        if(sum!=sum_o)
            continue;
        cout<<"16 "<<sum_o<<" "<<sum<<endl;

        cout<<intput<<endl;

    }
    return 0 ;
}
