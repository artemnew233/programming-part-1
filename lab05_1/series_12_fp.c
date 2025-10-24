#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

int main(void)
{
    double x;
    printf("Enter x: ");
    if (scanf("%lf", &x) != 1)
    {
        puts("Write a number please");
        return 1;
    }

    const int N = 20;
    int n = 1;

    double S = 0.0;
    double xpow = x;

    do
    {
        double num = xpow * x;
        double denom = 2.0 * (double)n + 1.0;

        if (!isfinite(num) || denom == 0.0 || !isfinite(denom))
        {
            puts("NaN");
            return 3;
        }

        S += num / denom;

        xpow *= x;
        ++n;
    } while (n <= N);

    printf("%.10g\n", S);
    return 0;
}
