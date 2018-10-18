#include <iostream>
using namespace std;

int main()
{
	int value,temp,sum;
	for(int i=2992; i<=9999; i++)
	{
		value = i%10 + i/10%10 + i/100%10 + i/1000;
		//  12
		sum = 0;
		temp = i;
		while(temp)
		{
			sum += temp%12;
			temp /= 12;
		}
		if(sum != value)
			continue;

		//  16
		sum = 0;
		temp = i;
		while(temp)
		{
			sum += temp%16;
			temp /= 16;
		}
		if(sum != value)
			continue;

		// output
		cout << i << endl;
	}
	return 0;
}
