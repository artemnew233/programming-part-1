#include <stdio.h>
#include "lib.h"

int main(void)
{
    double r;

    r = expr1(0.0, 0.0, 4.0, 0.0, 0.0);
    printf("expr1(0,0,4,0,0) = %.10g\n", r);

    r = expr6(0.0, 2.0, 1.0, 3.141592653589793 / 4.0, 3.0);
    printf("expr6(0,2,1,pi/4,3) = %.10g\n", r);

    r = expr12(2.0, 0.5, 3.0, 1.0);
    printf("expr12(2,0.5,3,1) = %.10g\n", r);

    r = expr16(1.0, 2.0, 0.0, 1.0);
    printf("expr16(1,2,0,1) = %.10g\n", r);

    return 0;
}
