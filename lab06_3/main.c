#include <stdio.h>
#include "callbacks.h"

double identity(int x) { return (double)x; }
double square(int x) { return (double)(x * x); }
double recip_plus_one(int x) { return 1.0 / (x + 1.0); }

int main(void)
{
    puts("print_table(1, 5, identity):");
    print_table(1, 5, identity);

    puts("\nprint_table(-2, 2, square):");
    print_table(-2, 2, square);

    puts("\nprint_table(0, 4, recip_plus_one):");
    print_table(0, 4, recip_plus_one);

    puts("\nEdge cases (no output expected):");
    print_table(5, 3, identity);
    print_table(1, 3, NULL);

    return 0;
}
