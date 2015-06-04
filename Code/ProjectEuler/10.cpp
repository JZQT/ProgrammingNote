#include <stdio.h>
#include <string.h>

const int N = 2000001;

int primes[N], pn;
bool isprime[N];
long long ans = 0;

void fast_sieve(int maxn)
{
    memset(isprime, true, sizeof(isprime));
    pn = 0;
    for (int i=2; i<=maxn; ++i)
    {
        if (isprime[i])
        {
            primes[pn++] = i;
            ans += i;
        }
        for (int j=0; j<pn; ++j)
        {
            if (i * primes[j] > maxn) break;
            isprime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
    return;
}

int main()
{
    fast_sieve(N-1);
    printf("%lld\n", ans);
    return 0;
}
