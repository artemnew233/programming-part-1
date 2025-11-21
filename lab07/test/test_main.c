#include "unity.h"

void test_expr12_simple_case(void);
void test_expr12_another_case(void);

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_expr12_simple_case);
    RUN_TEST(test_expr12_another_case);
    return UNITY_END();
}
