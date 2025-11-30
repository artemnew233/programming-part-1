#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MEMBERS 50
#define MAX_BOOKS 100
#define MAX_NAME_LENGTH 50
#define MAX_TITLE_LENGTH 100

typedef struct
{
    char title[MAX_TITLE_LENGTH];
} Book;

typedef struct
{
    char member_name[MAX_NAME_LENGTH];
    char book_title[MAX_TITLE_LENGTH];
} BorrowedBook;

typedef struct
{
    char name[MAX_NAME_LENGTH];
} Member;

typedef struct
{
    Member members[MAX_MEMBERS];
    int member_count;
    BorrowedBook borrowed_books[MAX_BOOKS];
    int borrowed_count;
} Library;

void init_library(Library *lib);
bool addMember(Library *lib, const char *name);
bool recordBorrow(Library *lib, const char *member_name, const char *book_title);
void listBorrowedBooks(Library *lib, const char *member_name);

void init_library(Library *lib)
{
    lib->member_count = 0;
    lib->borrowed_count = 0;
}

bool addMember(Library *lib, const char *name)
{
    if (lib->member_count >= MAX_MEMBERS)
    {
        printf("Error: Cannot add member. Member limit reached.\n");
        return false;
    }
    for (int i = 0; i < lib->member_count; i++)
    {
        if (strcmp(lib->members[i].name, name) == 0)
        {
            printf("Error: Member '%s' already exists.\n", name);
            return false;
        }
    }

    strcpy(lib->members[lib->member_count].name, name);
    lib->member_count++;
    return true;
}

bool recordBorrow(Library *lib, const char *member_name, const char *book_title)
{
    if (lib->borrowed_count >= MAX_BOOKS)
    {
        printf("Error: Cannot record borrow. Borrowed book limit reached.\n");
        return false;
    }

    bool member_found = false;
    for (int i = 0; i < lib->member_count; i++)
    {
        if (strcmp(lib->members[i].name, member_name) == 0)
        {
            member_found = true;
            break;
        }
    }

    if (!member_found)
    {
        printf("Error: Member '%s' not found. Cannot record borrow.\n", member_name);
        return false;
    }

    strcpy(lib->borrowed_books[lib->borrowed_count].member_name, member_name);
    strcpy(lib->borrowed_books[lib->borrowed_count].book_title, book_title);
    lib->borrowed_count++;
    return true;
}

void listBorrowedBooks(Library *lib, const char *member_name)
{
    printf("\nBorrowed Books for %s \n", member_name);
    int found_count = 0;
    for (int i = 0; i < lib->borrowed_count; i++)
    {
        if (strcmp(lib->borrowed_books[i].member_name, member_name) == 0)
        {
            printf("- %s\n", lib->borrowed_books[i].book_title);
            found_count++;
        }
    }

    if (found_count == 0)
    {
        printf("No books currently borrowed by %s.\n", member_name);
    }
}

int main()
{
    Library central_library;
    init_library(&central_library);

    printf("1. Adding Members\n");
    addMember(&central_library, "Artem");
    addMember(&central_library, "Maria");
    addMember(&central_library, "John");
    addMember(&central_library, "Artem");

    printf("\n2. Recording Borrows\n");
    recordBorrow(&central_library, "Artem", "The C Programming Language");
    recordBorrow(&central_library, "Maria", "Data Structures in C");
    recordBorrow(&central_library, "Artem", "Effective C++");
    recordBorrow(&central_library, "NonExistent", "Fake Book Title");

    printf("\n3. Listing Borrowed Books\n");
    listBorrowedBooks(&central_library, "Artem");
    listBorrowedBooks(&central_library, "Maria");
    listBorrowedBooks(&central_library, "John");

    return 0;
}
