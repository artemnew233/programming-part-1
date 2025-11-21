#include "lib.h"
#include <math.h>

/**
 * @brief Calculates the expression: (x - sin(y)) * z^2 + exp(w)
 * 
 * @param x The first variable.
 * @param y The second variable.
 * @param z The third variable.
 * @param w The fourth variable.
 * @return The result of the expression.
 */
double expr12(double x, double y, double z, double w)
{
    double term1 = x - sin(y); // (x - sin(y))
    double term2 = z * z;      // z^2
    double term3 = exp(w);     // exp(w)

    return (term1 * term2) + term3;
}
