#include <stdio.h>
#include <math.h>

int main()
{
    long long n = 600851475143LL;
    long long cnt = (long long)sqrt(n + 0.5) + 1;
    long long maxpf = 2;
    for (long long i=2; i<cnt; ++i)
    {
        if (n % i == 0)
        {
            maxpf = i;
            while (n % i == 0) n /= i;
        }
        if (n == 1) break;
    }
    if (n > 1) maxpf = n;
    printf("%lld\n", maxpf);
    return 0;
}
