#include <stdio.h>
#include <time.h>

int digit_difference_recursive(int number)
{
    if (number < 0)
    {
        number = -number;
    }

    if (number < 10)
    {
        if (number % 2 == 0)
        {
            return number;
        }
        else
        {
            return -number;
        }
    }

    int last_digit = number % 10;
    int rest = number / 10;

    if (last_digit % 2 == 0)
    {
        return last_digit + digit_difference_recursive(rest);
    }
    else
    {
        return -last_digit + digit_difference_recursive(rest);
    }
}

int digit_difference_iterative(int number)
{
    if (number < 0)
    {
        number = -number;
    }

    int even_sum = 0;
    int odd_sum = 0;

    if (number == 0)
    {
        return 0;
    }

    while (number > 0)
    {
        int digit = number % 10;

        if (digit % 2 == 0)
        {
            even_sum += digit;
        }
        else
        {
            odd_sum += digit;
        }

        number = number / 10;
    }

    return even_sum - odd_sum;
}

int main()
{

    printf("  Recursive vs Iterative\n");

    int iterations = 10000000;
    int test_number = 123456789;

    printf("Test number: %d\n", test_number);
    printf("Iterations: %d\n\n", iterations);

    int result_recursive = digit_difference_recursive(test_number);
    int result_iterative = digit_difference_iterative(test_number);

    printf("Quick verification:\n");
    printf("  Recursive result: %d\n", result_recursive);
    printf("  Iterative result: %d\n", result_iterative);

    if (result_recursive == result_iterative)
    {
        printf(" Both methods agree!\n\n");
    }
    else
    {
        printf("  ✗ ERROR: Results don't match!\n\n");
        return 1;
    }

    printf("Testing RECURSIVE version...\n");
    clock_t start_recursive = clock();

    int i;
    int dummy_result;
    for (i = 0; i < iterations; i++)
    {
        dummy_result = digit_difference_recursive(test_number);
    }

    clock_t end_recursive = clock();
    double time_recursive = ((double)(end_recursive - start_recursive)) / CLOCKS_PER_SEC;

    clock_t start_iterative = clock();

    for (i = 0; i < iterations; i++)
    {
        dummy_result = digit_difference_iterative(test_number);
    }

    clock_t end_iterative = clock();
    double time_iterative = ((double)(end_iterative - start_iterative)) / CLOCKS_PER_SEC;

    printf("             FINAL RESULTS              \n");

    printf("Speed comparison:\n");
    printf("  Recursive time: %.6f seconds\n", time_recursive);
    printf("  Iterative time: %.6f seconds\n\n", time_iterative);

    if (time_iterative < time_recursive)
    {
        double speedup = time_recursive / time_iterative;
        printf("ITERATIVE!\n");
        printf("  It's %.2fx faster!\n\n", speedup);
    }
    else
    {
        double speedup = time_iterative / time_recursive;
        printf("RECURSIVE!\n");
        printf("  It's %.2fx faster!\n\n", speedup);
    }
    return 0;
}
