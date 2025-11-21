#include "lib.h"
#include <math.h>

/**
 * @brief
 * @param x
 * @param y
 * @param z
 * @param w
 * @return
 */
double expr12(double x, double y, double z, double w)
{
    double term1 = x - sin(y);
    double term2 = z * z;
    double term3 = exp(w);

    return (term1 * term2) + term3;
}
