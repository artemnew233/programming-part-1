#include <stdio.h>
#include "include/user_macros.h"

int main(void)
{
    double out;
    SERIES_AR_SUM(out, 2.0, 3.0, 5);
    printf("AR: a1=2,d=3,n=5 -> S = %.6f (expected 40)\n", out);

    SERIES_AR_SUM(out, 1.5, -0.5, 4);
    printf("AR: a1=1.5,d=-0.5,n=4 -> S = %.6f\n", out);

    SERIES_AR_SUM(out, 10.0, 1.0, 0);
    printf("AR: n=0 -> S = %.6f (expected 0)\n", out);

    SERIES_GEOM_SUM(out, 1.0, 2.0, 4);
    printf("GEOM: a0=1,q=2,n=4 -> S = %.6f (expected 15)\n", out);

    SERIES_GEOM_SUM(out, 3.0, 1.0, 5);
    printf("GEOM: a0=3,q=1,n=5 -> S = %.6f (expected 15)\n", out);

    SERIES_GEOM_SUM(out, 2.0, 0.5, 3);
    printf("GEOM: a0=2,q=0.5,n=3 -> S = %.6f (expected 3.5)\n", out);

    SERIES_GEOM_SUM(out, 5.0, -2.0, 3);
    printf("GEOM: a0=5,q=-2,n=3 -> S = %.6f\n", out);

    SERIES_GEOM_SUM(out, 1.0, 2.0, 0);
    printf("GEOM: n=0 -> S = %.6f (expected 0)\n", out);

    return 0;
}
