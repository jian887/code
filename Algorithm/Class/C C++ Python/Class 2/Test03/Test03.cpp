#include <iostream>
using namespace std;

int main()
{
    int n,t=0;
    // ��������Ϊ>0 ����3 ����ô3&&3>0 Ϊ��
    // ��������Ϊ0,��ô0&&0 Ϊ��
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
