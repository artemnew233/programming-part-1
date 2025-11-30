#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void print_matrix(int N, int matrix[N][N])
{
    printf("Matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int find_max_upper_triangle(int N, int matrix[N][N])
{
    int max_val = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (matrix[i][j] > max_val)
            {
                max_val = matrix[i][j];
            }
        }
    }
    return max_val;
}

void reverse_each_row(int N, int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;
        while (left < right)
        {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}

int sum_positive_elements(int N, int matrix[N][N])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] > 0)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int compare_ints(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int find_second_smallest(int N, int matrix[N][N])
{
    int size = N * N;
    int flat_array[size];
    int k = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            flat_array[k++] = matrix[i][j];
        }
    }

    qsort(flat_array, size, sizeof(int), compare_ints);

    if (size < 2)
        return flat_array[0];

    int smallest = flat_array[0];
    for (int i = 1; i < size; i++)
    {
        if (flat_array[i] > smallest)
        {
            return flat_array[i];
        }
    }
    return smallest;
}

int main()
{
    int N = 4;
    int matrix[4][4] = {
        {1, 5, -3, 8},
        {9, 2, 7, -4},
        {6, 10, 3, 0},
        {-1, 12, 4, 11}};

    printf("--- Original Matrix ---\n");
    print_matrix(N, matrix);
    printf("\n");

    int max_upper = find_max_upper_triangle(N, matrix);
    printf("1. Max in Upper Triangle (i < j): %d\n", max_upper);

    int matrix_rev[4][4];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matrix_rev[i][j] = matrix[i][j];
    reverse_each_row(N, matrix_rev);
    printf("\n2. Matrix after reversing each row:\n");
    print_matrix(N, matrix_rev);

    int sum_pos = sum_positive_elements(N, matrix);
    printf("\n3. Sum of Positive Elements: %d\n", sum_pos);

    int second_smallest = find_second_smallest(N, matrix);
    printf("\n4. Second Smallest Unique Element: %d\n", second_smallest);

    return 0;
}
