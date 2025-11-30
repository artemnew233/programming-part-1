#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    const double EPS = 1e-9;
    double x, y;
    printf("Enter x: ");
    if (scanf("%lf", &x) != 1)
    {
        puts("Expected a number");
        return 0;
    }
    printf("Enter y: ");
    if (scanf("%lf", &y) != 1)
    {
        puts("Expected a number");
        return 0;
    }

    const double x_min = -2.0, x_max = 2.0;
    const double y_min = -1.0, y_max = 3.0;

    bool in_rect = (x >= x_min - EPS) && (x <= x_max + EPS) && (y >= y_min - EPS) && (y <= y_max + EPS);

    bool in_tria = false;

    double edge1 = y - x;
    double edge2 = y + x;
    double edge3 = y - 2.0;

    in_tria = (edge1 >= -EPS) && (edge2 >= -EPS) && (edge3 <= EPS);

    bool in_shaded_region = in_rect && !in_tria;

    if (in_shaded_region)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }

    return 0;
}