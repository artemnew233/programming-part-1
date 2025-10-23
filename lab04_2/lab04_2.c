#include <stdio.h>

int main(void)
{
    double base;
    int code;

    printf("Enter base price: ");
    if (scanf("%lf", &base) != 1)
    {
        puts("You wrote not a number");
        return 0;
    }
    if (base < 0.0)
    {
        puts("The number cant be negative");
        return 0;
    }

    printf("Enter tax code (1 -> 5%%, 2 -> 10%%, 3 -> 20%%): ");
    if (scanf("%d", &code) != 1)
    {
        puts("Invalid input: expected an integer tax code.");
        return 0;
    }

    double rate;
    switch (code)
    {
    case 1:
        rate = 0.05;
        break;
    case 2:
        rate = 0.10;
        break;
    case 3:
        rate = 0.20;
        break;
    default:
        printf("Error: invalid tax code (%d). Valid codes: 1, 2, 3.\n", code);
        return 0;
    }

    double total = base * (1.0 + rate);
    printf("Base: %.2f\nTax rate: %.2f%%\nTotal price: %.2f\n", base, rate * 100.0, total);

    return 0;
}
