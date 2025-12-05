#include <stdio.h>
#include <ctype.h>

int main(void)
{
    unsigned long long n = 0;
    int ch;

    printf("Enter a number in Base 5: ");

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (ch >= '0' && ch <= '4')
        {
            n = n * 5 + (ch - '0');
        }
    }

    printf("Decimal (Base 10): %llu\n", n);

    printf("\nEnter a number in Base 10: ");
    if (scanf("%llu", &n) != 1)
    {
        return 1;
    }

    printf("Base 5: ");

    if (n == 0)
    {
        putchar('0');
    }
    else
    {
        unsigned long long p = 1;
        while (p <= n / 5)
        {
            p *= 5;
        }

        while (p > 0)
        {
            unsigned d = (unsigned)(n / p);
            putchar('0' + d);
            n %= p;
            p /= 5;
        }
    }
    putchar('\n');

    return 0;
}
