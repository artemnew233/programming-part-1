#include "unity.h"
#include "lib.h"
#include <math.h>

void setUp(void) {}
void tearDown(void) {}

void test_expr12_simple_case(void)
{
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
    double x = 1.0;
    double y = M_PI / 2.0;
    double z = 1.0;
    double w = 1.0;

    double expected = M_E;
    double actual = expr12(x, y, z, w);

    TEST_ASSERT_FLOAT_WITHIN(1e-6, expected, actual);
}
