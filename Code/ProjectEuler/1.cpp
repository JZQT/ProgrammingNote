#include <stdio.h>

int main()
{
    int ans = 0;
    int blow = 1000 - 1;
    ans += (blow / 3) * (3 + blow / 3 * 3) / 2;
    ans += (blow / 5) * (5 + blow / 5 * 5) / 2;
    ans -= (blow / 15) * (15 + blow / 15 * 15) / 2;
    printf("%d\n", ans);
    return 0;
}
