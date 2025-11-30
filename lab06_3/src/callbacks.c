#include "callbacks.h"
#include <stdio.h>

void print_table(int from, int to, FuncIntToDouble f)
{
    if (!f)
        return;
    if (from > to)
        return;

    for (int i = from; i <= to; ++i)
    {
        double v = f(i);
        printf("%d -> %.6f\n", i, v);
    }
}
