#include <stdio.h>
#include <string.h>
#include <math.h>

bool palindrome(int num)
{
    char str[10];
    sprintf(str, "%d", num);
    int len = strlen(str);
    int cnt = len / 2;
    for (int i=0; i<cnt; ++i)
    {
        if (str[i] != str[len-i-1]) return false;
    }
    return true;
}

int main()
{
    int number = 999 * 999 + 1;
    int ans = 0;
    while (number--)
    {
        if (!palindrome(number)) continue;
        int cnt = (int)sqrt(number + 0.5) + 1;
        for (int i=100; i<cnt; ++i)
        {
            if (number % i != 0) continue;
            int tmp = number / i;
            if (tmp < 100 || tmp > 999) continue;
            ans = number;
            break;
        }
        if (ans != 0) break;
    }
    printf("%d\n", ans);
    return 0;
}
