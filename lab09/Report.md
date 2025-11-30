# Lab 09 — Lab Work Report

---
**Course:** Programming, Part 1
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Smeliantsev Artem 
**Date:** 30.11.2025

---

## Task Description

The objective of this lab was to implement a **Library Membership System** using C structures (structs) for **Variant 12**. The system required defining nested structs and implementing functions to manage members and record borrowed books.

### System Components

| Component | Struct | Key Fields | Functions Implemented |
| :--- | :--- | :--- | :--- |
| **Member** | `Member` | `name` | `addMember` |
| **Borrowed Book** | `BorrowedBook` | `member_name`, `book_title` | `recordBorrow` |
| **System Container** | `Library` | `members[]`, `borrowed_books[]` | `init_library`, `listBorrowedBooks` |

## Report

The goal of this lab was to gain practical experience with defining and manipulating C structs, especially in a system that requires managing collections of data.

In this lab, I completed the following tasks:

1.  **Defined** the necessary structs (`Member`, `BorrowedBook`, `Library`) using `typedef` for cleaner code.
2.  **Implemented** the `addMember` function, which includes a check to prevent adding duplicate members and ensures the array limit is not exceeded.
3.  **Implemented** the `recordBorrow` function, which validates that the member exists before recording the transaction.
4.  **Implemented** the `listBorrowedBooks` function to display all books currently borrowed by a specific member.

### Implementation Details

The core of the solution is the `Library` struct, which holds the arrays of all members and all borrowed book records. Functions are passed a pointer to the `Library` struct (`Library *lib`) to allow them to modify the central data structure. String comparison (`strcmp`) and copying (`strcpy`) were used extensively to handle the text fields (names and titles).

### Runtime Output

The program was tested with a sequence of operations to demonstrate all required functions, including error handling for duplicates and non-existent members.

```text
1. Adding Members
Error: Member 'Artem' already exists.

2. Recording Borrows
Error: Member 'NonExistent' not found. Cannot record borrow.

3. Listing Borrowed Books

Borrowed Books for Artem 
- The C Programming Language
- Effective C++

Borrowed Books for Maria 
- Data Structures in C

Borrowed Books for John 
No books currently borrowed by John.
```
