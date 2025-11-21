#include <stdio.h>
#include <math.h>
#include "lib.h"

int main(void)
{
    // Example usage of the expression function: (x - sin(y)) * z^2 + exp(w)
    
    // Case 1: x=2, y=0, z=3, w=0 -> Result: 19.0
    double x1 = 2.0;
    double y1 = 0.0;
    double z1 = 3.0;
    double w1 = 0.0;
    
    double result1 = expr12(x1, y1, z1, w1);
    
    printf("Case 1: (x=%.2f, y=%.2f, z=%.2f, w=%.2f)\n", x1, y1, z1, w1);
    printf("Result: %.10f\n", result1);
    
    // Case 2: x=1, y=M_PI/2, z=1, w=1 -> Result: M_E (approx 2.718)
    double x2 = 1.0;
    double y2 = M_PI / 2.0;
    double z2 = 1.0;
    double w2 = 1.0;
    
    double result2 = expr12(x2, y2, z2, w2);
    
    printf("\nCase 2: (x=%.2f, y=%.2f, z=%.2f, w=%.2f)\n", x2, y2, z2, w2);
    printf("Result: %.10f\n", result2);

    return 0;
}
