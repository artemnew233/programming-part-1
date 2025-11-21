#include "unity.h"
#include "lib.h"
#include <math.h>

void setUp(void) {}
void tearDown(void) {}

void test_expr12_simple_case(void)
{
    // Test case 1: x=2, y=0, z=3, w=0
    // Expected result: (2 - sin(0)) * 3^2 + exp(0)
    //                = (2 - 0) * 9 + 1
    //                = 18 + 1 = 19.0
    double x = 2.0;
    double y = 0.0;
    double z = 3.0;
    double w = 0.0;
    
    double expected = 19.0;
    double actual = expr12(x, y, z, w);

    TEST_ASSERT_FLOAT_WITHIN(1e-6, expected, actual);
}

void test_expr12_another_case(void)
{
    // Test case 2: x=1, y=M_PI/2, z=1, w=1
    // Expected result: (1 - sin(M_PI/2)) * 1^2 + exp(1)
    //                = (1 - 1) * 1 + exp(1)
    //                = 0 + exp(1) = M_E
    double x = 1.0;
    double y = M_PI / 2.0;
    double z = 1.0;
    double w = 1.0;
    
    double expected = M_E;
    double actual = expr12(x, y, z, w);

    TEST_ASSERT_FLOAT_WITHIN(1e-6, expected, actual);
}
