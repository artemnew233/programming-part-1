#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter integer n (0..9999): ");
    if (scanf("%d", &n) != 1)
    {
        puts("Invalid input");
        return 1;
    }

    if (n < 0 || n > 9999)
    {
        puts("Error: n must be in range 0..9999");
        return 2;
    }

    int d1 = (n / 1000) % 10;
    int d2 = (n / 100) % 10;
    int d3 = (n / 10) % 10;
    int d4 = n % 10;

    int exactly_three = 0;

    if (d1 == d2)
    {
        if (d2 == d3)
        {
            if (d3 != d4)
                exactly_three = 1;
            else
                exactly_three = 0;
        }
        else
        {
            if (d2 == d4)
            {
                if (d4 != d3)
                    exactly_three = 1;
                else
                    exactly_three = 0;
            }
            else
            {
                exactly_three = 0;
            }
        }
    }
    else
    {
        if (d1 == d3)
        {
            if (d3 == d4)
            {
                if (d4 != d2)
                    exactly_three = 1;
                else
                    exactly_three = 0;
            }
            else
            {
                exactly_three = 0;
            }
        }
        else
        {
            if (d1 == d4)
            {
                if (d2 == d3 && d3 == d4 && d4 != d1)
                    exactly_three = 1;
                else
                    exactly_three = 0;
            }
            else
            {
                /* d1 not equal to d2,d3,d4 -> check if d2==d3==d4 */
                if (d2 == d3)
                {
                    if (d3 == d4)
                    {
                        if (d4 != d1)
                            exactly_three = 1;
                        else
                            exactly_three = 0;
                    }
                    else
                    {
                        exactly_three = 0;
                    }
                }
                else
                {
                    exactly_three = 0;
                }
            }
        }
    }

    /* Output - YES if exactly three identical digits, NO otherwise */
    if (exactly_three)
        puts("YES");
    else
        puts("NO");

    return 0;
}
