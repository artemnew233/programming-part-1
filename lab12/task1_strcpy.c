#include <stdio.h>

int strcmp_manual(const char *s1, const char *s2);

char *my_strcpy(char *dest, const char *src)
{
    char *original_dest = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return original_dest;
}

void test_strcpy()
{
    printf("========================================\n");
    printf("Testing my_strcpy() implementation\n");
    printf("========================================\n\n");

    char dest1[50];
    char src1[] = "Hello, World!";
    my_strcpy(dest1, src1);
    printf("Test 1 - Basic copy:\n");
    printf("  Source: '%s'\n", src1);
    printf("  Destination: '%s'\n", dest1);
    printf("  Result: %s\n\n", (strcmp_manual(dest1, src1) == 0) ? "PASS" : "FAIL");

    char dest2[50];
    char src2[] = "";
    my_strcpy(dest2, src2);
    printf("Test 2 - Empty string:\n");
    printf("  Source: '%s'\n", src2);
    printf("  Destination: '%s'\n", dest2);
    printf("  Result: %s\n\n", (strcmp_manual(dest2, src2) == 0) ? "PASS" : "FAIL");

    char dest3[50];
    char src3[] = "A";
    my_strcpy(dest3, src3);
    printf("Test 3 - Single character:\n");
    printf("  Source: '%s'\n", src3);
    printf("  Destination: '%s'\n", dest3);
    printf("  Result: %s\n\n", (strcmp_manual(dest3, src3) == 0) ? "PASS" : "FAIL");

    char dest4[100];
    char src4[] = "The quick brown fox jumps over the lazy dog";
    my_strcpy(dest4, src4);
    printf("Test 4 - Long string:\n");
    printf("  Source: '%s'\n", src4);
    printf("  Destination: '%s'\n", dest4);
    printf("  Result: %s\n\n", (strcmp_manual(dest4, src4) == 0) ? "PASS" : "FAIL");

    char dest5[50];
    char src5[] = "Test123456";
    my_strcpy(dest5, src5);
    printf("Test 5 - String with numbers:\n");
    printf("  Source: '%s'\n", src5);
    printf("  Destination: '%s'\n", dest5);
    printf("  Result: %s\n\n", (strcmp_manual(dest5, src5) == 0) ? "PASS" : "FAIL");

    printf("========================================\n");
}

int strcmp_manual(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main()
{
    test_strcpy();
    return 0;
}
