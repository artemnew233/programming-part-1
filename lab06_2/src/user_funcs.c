#include <math.h>

static inline double series_ar_sum_fn(double a1, double d, long n)
{
    if (n <= 0)
        return 0.0;
    return ((double)n) / 2.0 * (2.0 * a1 + ((double)(n)-1.0) * d);
}

static inline double series_geom_sum_fn(double a0, double q, long n)
{
    if (n <= 0)
        return 0.0;
    const double eps = 1e-12;
    if (fabs(q - 1.0) < eps)
        return ((double)n) * a0;
    return a0 * (1.0 - pow(q, (double)n)) / (1.0 - q);
}
