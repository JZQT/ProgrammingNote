#include <stdio.h>

const int N = 4000000;

int main()
{
    int a = 3, b = 5, c = 8;
    int ans = 2;
    while (c <= N)
    {
        ans += c;
        a = b + c;
        b = a + c;
        c = a + b;
    }
    printf("%d\n", ans);
    return 0;
}
