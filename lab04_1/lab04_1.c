#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter number n (0-9999): ");
    if (scanf("%d", &n) != 1)
    {
        puts("Invalid input, write a number");
        return 0;
    }

    if (n < 0 || n > 9999)
    {
        puts("Error: n must be in range 0-9999");
        return 0;
    }

    int d1 = (n / 1000) % 10;
    int d2 = (n / 100) % 10;
    int d3 = (n / 10) % 10;
    int d4 = n % 10;
    if (d1 == 0 && d2 == 0 && d3 == 0)
    {
        printf("The number has only one digit: %d\n", d4);
        puts("NO");
        return 0;
    }
    if (d1 == d2)
    {
        if (d2 == d3)
        {
            if (d3 == d4)
            {
                printf("YES, %d has 4 same digits %d", n, d1); // --> yes
            }
            else
            {
                printf("YES, %d has 3 same digits %d", n, d1); // --> yes
            }
            return 0;
        }
        if (d2 == d4)
        {
            printf("YES, %d has 3 same digits %d", n, d1); // --> yes
            return 0;
        }
        else
        {
            printf("NO, there are no same digits in %d", n); // --> no
            return 0;
        }
    }
    if (d1 == d3)
    {
        if (d3 == d4)
        {
            printf("YES, %d has 3 same digits %d", n, d1);
            return 0;
        }
        else
        {
            printf("NO, there are no same digits in %d", n);
            return 0;
        }
    }
    if (d2 == d3)
    {
        if (d3 == d4)
        {
            printf("YES, %d has 3 same digits %d", n, d2);
            return 0;
        }
        else
        {
            printf("NO, there are no same digits in %d", n);
            return 0;
        }
    }
    else
    {
        printf("NO, there are no same digits in %d", n);
        return 0;
    }
}
