#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        puts("Invalid n");
        return 1;
    }

    const double a = 0.0;
    const double b = 4.0;
    const double PI = acos(-1.0);

    double step = 0.0;
    if (n == 1)
    {
        step = 0.0;
    }
    else
    {
        step = (b - a) / (double)(n - 1);
    }
    int i = 0;
    while (i < n)
    {
        double x = a + i * step;

        double denom_arg = 12.0 - x;
        double y;
        if (!isfinite(x) || denom_arg <= 0.0 || !isfinite(denom_arg))
        {
            y = NAN;
        }
        else
        {
            double denom = sqrt(denom_arg);
            double num = sin(PI / 2.0 - x / 4.0);
            y = num / denom;
            if (!isfinite(y))
                y = NAN;
        }

        printf("%10.5f %12.5f\n", x, y);
        ++i;
    }

    return 0;
}
