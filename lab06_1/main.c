#include <stdio.h>
#include "include/user_funcs.h"

int main(void)
{
    double a0, q;
    unsigned n;

    printf("Geometric series (variant 12): S_n = a0 + a0*q + ... (n terms)\n");
    printf("Enter a0 q n  (example: 2 0.5 5): ");
    if (scanf("%lf %lf %u", &a0, &q, &n) == 3)
    {
        double s = series_geom(a0, q, n);
        printf("series_geom(%.6g, %.6g, %u) = %.10g\n\n", a0, q, n, s);
    }
    else
    {
        printf("Invalid input for geometric series.\n\n");
        return 0;
    }

    double a1, d;
    printf("Arithmetic series: S_n = a1 + (a1+d) + ... (n terms)\n");
    printf("Enter a1 d n  (example: 3 2 4): ");
    if (scanf("%lf %lf %u", &a1, &d, &n) == 3)
    {
        double s2 = series_arith(a1, d, n);
        printf("series_arith(%.6g, %.6g, %u) = %.10g\n", a1, d, n, s2);
    }
    else
    {
        printf("Invalid input for arithmetic series.\n");
        return 0;
    }

    return 0;
}
