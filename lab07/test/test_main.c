#include "unity.h"

void test_expr1_simple(void);
void test_expr6_simple(void);
void test_expr12_example(void);
void test_expr16_example(void);

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_expr1_simple);
    RUN_TEST(test_expr6_simple);
    RUN_TEST(test_expr12_example);
    RUN_TEST(test_expr16_example);
    return UNITY_END();
}
