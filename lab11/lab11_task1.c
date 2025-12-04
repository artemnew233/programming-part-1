#include <stdio.h>

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

void show_breakdown(int number)
{
    if (number < 0)
    {
        number = -number;
    }

    printf("\nBreakdown for %d:\n", number);

    int even_sum = 0;
    int odd_sum = 0;
    int temp = number;

    printf("Even digits: ");
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit % 2 == 0)
        {
            printf("%d ", digit);
            even_sum += digit;
        }
        temp = temp / 10;
    }
    printf("-> Sum = %d\n", even_sum);

    temp = number;
    printf("Odd digits:  ");
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit % 2 == 1)
        {
            printf("%d ", digit);
            odd_sum += digit;
        }
        temp = temp / 10;
    }
    printf("-> Sum = %d\n", odd_sum);

    printf("Difference: %d - %d = %d\n", even_sum, odd_sum, even_sum - odd_sum);
}

int main()
{

    int test_numbers[] = {12345, 2468, 1357, 100, 999, 0, 42, -123};
    int num_tests = 8;

    printf("Testing recursive digit difference:\n");

    int i;
    for (i = 0; i < num_tests; i++)
    {
        int num = test_numbers[i];
        int result = digit_difference_recursive(num);

        printf("Number: %6d  ->  Difference: %3d", num, result);

        if (result > 0)
        {
            printf("  (Even wins!)\n");
        }
        else if (result < 0)
        {
            printf("  (Odd wins!)\n");
        }
        else
        {
            printf("  (It's a tie!)\n");
        }
    }

    for (i = 0; i < num_tests; i++)
    {
        int num = test_numbers[i];
        int recursive_result = digit_difference_recursive(num);
        int iterative_result = digit_difference_iterative(num);

        printf("Number: %6d  ->  Recursive: %3d, Iterative: %3d",
               num, recursive_result, iterative_result);

        if (recursive_result == iterative_result)
        {
            printf("  ✓\n");
        }
        else
        {
            printf("  ✗ ERROR!\n");
        }
    }

    printf("\n========================================\n");
    show_breakdown(12345);
    printf("========================================\n");

    printf("\nInteractive test - Enter a number: ");
    int user_number;
    scanf("%d", &user_number);

    int result = digit_difference_recursive(user_number);
    show_breakdown(user_number);

    printf("\nFinal result: %d\n", result);
    if (result > 0)
    {
        printf("Even digits are stronger! \n");
    }
    else if (result < 0)
    {
        printf("Odd digits are stronger! \n");
    }
    else
    {
        printf("Perfect balance! \n");
    }
    return 0;
}
