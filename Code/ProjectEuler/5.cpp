#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int ans = lcm(1, 2);
    for (int i=3; i<=20; ++i)
    {
        ans = lcm(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}
