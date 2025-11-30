#include <stdio.h>

double calculate_average(int size, int arr[])
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)sum / size;
}

int find_largest(int size, int arr[])
{
    if (size <= 0)
        return 0;
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void replace_negatives(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            arr[i] = 0;
        }
    }
}

void selection_sort(int size, int arr[])
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int count_unique(int size, int arr[])
{
    if (size == 0)
        return 0;

    int temp_arr[size];
    for (int i = 0; i < size; i++)
    {
        temp_arr[i] = arr[i];
    }
    selection_sort(size, temp_arr);

    int unique_count = 0;
    if (size > 0)
    {
        unique_count = 1;
        for (int i = 1; i < size; i++)
        {
            if (temp_arr[i] != temp_arr[i - 1])
            {
                unique_count++;
            }
        }
    }
    return unique_count;
}

void print_array(int size, int arr[])
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int size = 10;
    int array[] = {5, -2, 10, 5, 8, -2, 1, 10, 3, 1};

    printf("Array: ");
    print_array(size, array);

    double avg = calculate_average(size, array);
    printf("1. Average: %.2f\n", avg);

    int largest = find_largest(size, array);
    printf("2. Largest Element: %d\n", largest);

    int array_replace[] = {5, -2, 10, 5, 8, -2, 1, 10, 3, 1};
    replace_negatives(size, array_replace);
    printf("3. Array after replacing negatives: ");
    print_array(size, array_replace);

    int array_sort[] = {5, -2, 10, 5, 8, -2, 1, 10, 3, 1};
    selection_sort(size, array_sort);
    printf("4. Array after Selection Sort: ");
    print_array(size, array_sort);

    int unique_count = count_unique(size, array);
    printf("5. Count of Unique Elements: %d\n", unique_count);

    return 0;
}