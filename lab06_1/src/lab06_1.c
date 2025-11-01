#include "user_funcs.h"

double series_geom(double a0, double q, unsigned n)
{
    if (n == 0)
        return 0.0;

    double sum = 0.0;
    double term = a0;
    unsigned i = 0;
    while (i < n)
    {
        sum += term;
        term *= q;
        ++i;
    }
    return sum;
}
double series_arith(double a1, double d, unsigned n)
{
    if (n == 0)
        return 0.0;

    double sum = 0.0;
    double term = a1;
    unsigned i = 0;
    while (i < n)
    {
        sum += term;
        term += d;
        ++i;
    }
    return sum;
}
