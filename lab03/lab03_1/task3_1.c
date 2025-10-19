#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    double a, b, c, d, e, E;

    printf("Enter x: ");
    scanf("%lf", &x);

    a = x * x - 25.0;
    b = x - 5.0;
    c = 4.0 * x + 1.0;
    d = 3.0 * c;
    e = x + 2.0;

    E = a / b + d / e;

    printf("E(%.6f) = %.6f\n", x, E);
    return 0;
}