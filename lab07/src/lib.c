#include "lib.h"
#include <math.h>

double expr1(double x, double y, double z, double w, double v)
{
    double s = sin(x);
    double c = cos(y);
    double sq = sqrt(z);
    double e = exp(w);
    double t = tan(v);
    return s + c * sq + e + t;
}

double expr6(double x, double y, double z, double w, double v)
{
    double e = exp(x);
    double ysqr = y * y;
    double num = (e + ysqr - z) * tan(w);
    double den = sqrt(v + 1.0);
    return num / den;
}

double expr12(double x, double y, double z, double w)
{
    double s = sin(y);
    double z2 = z * z;
    double e = exp(w);
    return (x - s) * z2 + e;
}

double expr16(double x, double y, double z, double w)
{
    double ysqr = y * y;
    double c = cos(z);
    double lnpart = log(w + 1.0);
    return (x + ysqr) - c * lnpart;
}
