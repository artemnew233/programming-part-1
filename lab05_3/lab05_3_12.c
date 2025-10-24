#include <stdio.h>
#include <ctype.h>

int main(void)
{
    unsigned long long v = 0ULL;
    int ch;
    unsigned int digit;
    int overflow = 0;
    const unsigned long long MAX = (unsigned long long)(-1);

    printf("Base-5 -> Decimal conversion\n");
    printf("Enter base-5 number (digits 0..4), then Enter: ");

    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (ch == ' ' || ch == '\t')
            continue;
        if (ch >= '0' && ch <= '4')
        {
            digit = (unsigned int)(ch - '0');
            if (v > MAX / 5ULL)
            {
                overflow = 1;
                break;
            }
            v = v * 5ULL + (unsigned long long)digit;
            if (v < (unsigned long long)digit)
            {
                overflow = 1;
                break;
            }
        }
        else
        {
            fprintf(stderr, "Invalid digit '%c' encountered — allowed digits: 0..4\n", ch);
            while (ch != EOF && ch != '\n')
                ch = getchar();
            return 0;
        }
    }

    if (overflow)
    {
        puts("OVERFLOW while converting base-5 to decimal");
        return 3;
    }

    printf("Decimal result: %llu\n", v);

    unsigned long long n = 0ULL;
    printf("\nDecimal -> Base-5 conversion\n");
    printf("Enter decimal (unsigned) number, then Enter: ");
    if (scanf("%llu", &n) != 1)
    {
        fprintf(stderr, "Failed to read decimal number\n");
        return 0;
    }
    unsigned long long p = 1ULL;
    if (n == 0ULL)
    {
        printf("Base-5: 0\n");
        return 0;
    }
    while (p <= n / 5ULL)
    {
        p *= 5ULL;
    }

    printf("Base-5 result: ");
    while (p > 0ULL)
    {
        unsigned long long d = n / p;
        putchar((char)('0' + (int)d));
        n %= p;
        p /= 5ULL;
    }
    putchar('\n');

    return 0;
}
