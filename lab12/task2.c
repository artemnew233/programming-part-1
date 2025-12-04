#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

void to_uppercase(char *line)
{
    int i = 0;
    while (line[i] != '\0')
    {
        if (line[i] >= 'a' && line[i] <= 'z')
        {
            line[i] = line[i] - 32;
        }
        i++;
    }
}

void replace_hello_with_hi(char *line)
{
    char temp[MAX_LINE];
    int i = 0, j = 0;

    while (i < strlen(line))
    {
        if (line[i] == 'h' && line[i + 1] == 'e' && line[i + 2] == 'l' &&
            line[i + 3] == 'l' && line[i + 4] == 'o')
        {
            temp[j++] = 'h';
            temp[j++] = 'i';
            i += 5;
        }
        else
        {
            temp[j++] = line[i];
            i++;
        }
    }
    temp[j] = '\0';
    strcpy(line, temp);
}

void process_line(char *line)
{
    to_uppercase(line);
    replace_hello_with_hi(line);
}

int process_file()
{
    FILE *input = fopen(INPUT_FILE, "r");
    if (!input)
    {
        perror("Cannot open input file");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(OUTPUT_FILE, "w");
    if (!output)
    {
        perror("Cannot open output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE];
    int line_count = 0;

    printf("Processing file...\n");
    printf("========================================\n");

    while (fgets(line, sizeof(line), input) != NULL)
    {
        process_line(line);
        fprintf(output, "%s", line);
        line_count++;
        printf("Line %d processed\n", line_count);
    }

    printf("========================================\n");
    printf("Total lines processed: %d\n", line_count);

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}

int main()
{
    printf("Lab 12 - Task 2: File Operations and String Manipulation\n");
    printf("Variant 1: Convert to uppercase + Replace 'hello' with 'hi'\n\n");

    int result = process_file();

    if (result == EXIT_SUCCESS)
    {
        printf("\nFile processing completed successfully!\n");
        printf("Output saved to: %s\n", OUTPUT_FILE);
    }
    else
    {
        printf("\nFile processing failed!\n");
    }

    return result;
}
