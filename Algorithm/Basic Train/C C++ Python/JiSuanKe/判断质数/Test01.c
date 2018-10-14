#include <iostream>
using namespace std;
int main()
{
 int a;
 cin >> a;
 for (int num = 2; num < 33; num++)
 {
 if (num == a)
 continue;
 if (a % num == 0)
 {
 cout << "NO" << endl;
 break;
 }
 if (num == 32)
 cout << "YES" << endl;
 }
 return 0;
}
/*
33 * 33 > 1000
*/
