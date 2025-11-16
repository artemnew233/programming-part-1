#include "unity.h"
#include <math.h>
#include "lib.h"

void setUp(void) {}
void tearDown(void) {}

void test_expr1_simple(void) {
    double got = expr1(0.0, 0.0, 4.0, 0.0, 0.0);
    double expected = 3.0;
    TEST_ASSERT_FLOAT_WITHIN(1e-6f, (float)expected, (float)got);
}

void test_expr6_simple(void) {
    double got = expr6(0.0, 2.0, 1.0, M_PI/4.0, 3.0);
    double expected = 1.5;
    TEST_ASSERT_FLOAT_WITHIN(1e-6f, (float)expected, (float)got);
}

void test_expr12_example(void) {
    double got = expr12(2.0, 0.5, 3.0, 1.0);
    double siny = sin(0.5);
    double expw = exp(1.0);
    double expected = (2.0 - siny) * (3.0 * 3.0) + expw;
    TEST_ASSERT_FLOAT_WITHIN(1e-6f, (float)expected, (float)got);
}

void test_expr16_example(void) {
    double got = expr16(1.0, 2.0, 0.0, 1.0);
    double expected = (1.0 + 4.0) - cos(0.0) * log(1.0 + 1.0);
    TEST_ASSERT_FLOAT_WITHIN(1e-6f, (float)expected, (float)got);
}
