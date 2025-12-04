#include <stdio.h>

void print_char_n_times(char c, int count)
{
    if (count <= 0)
    {
        return;
    }
    printf("%c", c);
    print_char_n_times(c, count - 1);
}

char get_symbol_for_row(int row)
{
    int remainder = row % 3;

    if (remainder == 1)
    {
        return '*';
    }
    else if (remainder == 2)
    {
        return '#';
    }
    else
    {
        return '+';
    }
}

void print_spaces(int count)
{
    if (count <= 0)
    {
        return;
    }
    printf(" ");
    print_spaces(count - 1);
}

void draw_pyramid_recursive(int current_row, int total_height)
{
    if (current_row > total_height)
    {
        return;
    }

    int spaces = total_height - current_row;
    int symbols = 2 * current_row - 1;

    char symbol = get_symbol_for_row(current_row);

    print_spaces(spaces);
    print_char_n_times(symbol, symbols);
    printf("\n");

    draw_pyramid_recursive(current_row + 1, total_height);
}

void draw_pyramid(int height)
{
    if (height <= 0)
    {
        printf("Height must be positive!\n");
        return;
    }

    draw_pyramid_recursive(1, height);
}

void draw_inverted_pyramid_recursive(int current_row, int total_height)
{
    if (current_row > total_height)
    {
        return;
    }

    draw_inverted_pyramid_recursive(current_row + 1, total_height);

    int spaces = total_height - current_row;
    int symbols = 2 * current_row - 1;
    char symbol = get_symbol_for_row(current_row);

    print_spaces(spaces);
    print_char_n_times(symbol, symbols);
    printf("\n");
}

void draw_inverted_pyramid(int height)
{
    if (height <= 0)
    {
        printf("Height must be positive!\n");
        return;
    }

    draw_inverted_pyramid_recursive(1, height);
}

int main()
{
    printf("========================================\n");
    printf("  Pyramid Builder 3000 - Variant 12   \n");
    printf("========================================\n\n");

    printf("Pyramid with height 3:\n");
    draw_pyramid(3);

    printf("\nPyramid with height 7:\n");
    draw_pyramid(7);

    printf("\n========================================\n");
    printf("Bonus: Inverted Pyramid\n");
    printf("========================================\n\n");

    printf("Inverted pyramid with height 5:\n");
    draw_inverted_pyramid(5);

    printf("Interactive mode - Enter pyramid height: ");
    int user_height;
    scanf("%d", &user_height);

    if (user_height <= 0)
    {
        printf("Height must be positive!\n");
    }
    else if (user_height > 30)
    {
        printf("That's too big! Let's do 30 instead:\n");
        draw_pyramid(30);
    }
    else
    {
        printf("\nYour pyramid with height %d:\n", user_height);
        draw_pyramid(user_height);
    }

    return 0;
}
