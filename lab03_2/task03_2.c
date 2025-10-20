#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    printf("Enter x: ");
    if (scanf("%lf", &x) != 1)
    {
        printf("Error: You have to write a number a number.\n");
        return 0;
    }
    double a = log(x);
    double b = sin(x);
    double c = cos(x);
    double d = exp(x);
    double e = x + 1.0;
    double E = a / b + (c * d) / e;
    printf("\nE(%.6f) = %.6f\n", x, E);
    return 0;
}
