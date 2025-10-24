#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>

int main(void)
{
    int64_t x;
    printf("Enter X: ");
    if (scanf("%" SCNd64, &x) != 1)
    {
        puts("Write a number please");
        return 1;
    }

    const int N = 20;
    int64_t S = 0;

    __int128 xpow = (__int128)x;

    for (int n = 1; n <= N; ++n)
    {
        __int128 pow_n1 = xpow * (__int128)x;

        int64_t denom = 2LL * n + 1LL;

        __int128 term = pow_n1 / (__int128)denom;

        if (term > (__int128)LLONG_MAX || term < (__int128)LLONG_MIN)
        {
            puts("OVERFLOW");
            return 2;
        }
        int64_t term64 = (int64_t)term;

        if ((term64 > 0 && S > LLONG_MAX - term64) ||
            (term64 < 0 && S < LLONG_MIN - term64))
        {
            puts("OVERFLOW");
            return 2;
        }

        S += term64;

        xpow = pow_n1;
    }

    printf("%" PRId64 "\n", S);
    return 0;
}
