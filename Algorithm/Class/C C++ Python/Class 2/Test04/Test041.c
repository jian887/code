#include<stdio.h>
int main()
{
    int m, n, r;
    while(scanf("%d %d", &m, &n), m + n != -2)
    {
        while(n != 0 && n != 1)
        {
            r = m % n;
            m = n;
            n = r;
        }
        puts(n ? "YES" : "POOR Haha");
    }
    return 0;
}
