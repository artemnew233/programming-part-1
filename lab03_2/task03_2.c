#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    printf("Enter x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Error: You have to write a number.\n");
        return 0;
    }
    double a = exp(0.5 * x);
    double b = log(x + 7.0);
    double c = sin(x);
    double d = tan(x);
    double e = cos(x);
    double denom = e - 1.0;

    double E = a / b + (c * d);

    printf("\nE(%.6f) = %.6f\n", x, E);
    return 0;
}