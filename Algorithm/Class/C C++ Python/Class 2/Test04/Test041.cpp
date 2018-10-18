#include <iostream>

using namespace std;
int gcd(int a , int b)
{
    return a % b ? gcd(b , a % b) : b;
}
int main()
{
    int m , n;
    while(cin >> m >> n && (m != -1|| n != -1))
    {
        cout << (gcd(m , n) == 1 ? "YES" : "POOR Haha") << endl;
    }
    return 0;
}