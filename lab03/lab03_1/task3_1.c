#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double x;
    double a, b, c, d, e, E;

    printf("Enter x: ");
    if (scanf("%lf", &x) != 1)
    {
        fprintf(stderr, "Error: invalid input. Expected a number.\n");
        return 0;
    }

    a = x * x - 2.0 * x - 3.0;
    b = x - 3.0;
    c = 2.0 * x + 5.0;
    d = x - 4.0;
    e = x + 2.0;

    E = a / b + (c * d) / e;

    printf("\nDebugger:\n");
    printf("a = x^2 - 2x - 3 = %.12f\n", a);
    printf("b = x - 3        = %.12f\n", b);
    printf("c = 2x + 5       = %.12f\n", c);
    printf("d = x - 4        = %.12f\n", d);
    printf("e = x + 2        = %.12f\n", e);

    printf("\nE(%.6f) = %.12f\n", x, E);
    return 0;
}
