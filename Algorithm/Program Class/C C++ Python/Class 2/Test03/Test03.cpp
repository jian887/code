#include <iostream>
using namespace std;

int main()
{
    int n,t=0;
    // 如果输入的为>0 比如3 ，那么3&&3>0 为真
    // 如果输入的为0,那么0&&0 为假
    while((cin>>n)||n){
        int sum = 0;
        int out = 0;
        int avg;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        avg = sum/n;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]>avg)
                out+=arr[i]-avg;
        }

            cout<<"Set #"<<++t<<endl<<"The minimum number of moves is "<<out<<"."<<endl<<endl;
    }
    return 0;
}
