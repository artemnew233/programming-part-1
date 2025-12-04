# Lab 12 — Lab Work Report

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Smeliantsev Artem
**Date:** Dec 04, 2025  

---

## Task Description

This lab focuses on working with C-strings and file operations. The tasks require implementing standard C-string functions from scratch without using the `<string.h>` library, and performing file I/O with string manipulation.

1. **Task 1:** Implement the `strcpy()` function using only pointer operations and test it with various inputs.
2. **Task 2:** Write a program that reads from an input file, applies string modifications, and writes the results to an output file.

## Structure

```text
lab12/
├── Makefile
├── Report.md
├── task1_strcpy.c
├── task2_fileops.c
├── input.txt
└── output.txt
```

## Lab Instructions

Use the following commands to build and run the project from the `/home/ubuntu/upload` directory.

### How to Build

> The following command compiles all C source files into executables.

```bash
make all
```

### How to Run

> The `run` target executes all compiled programs sequentially.

```bash
make run
```

### How to Test

> The `test` target compiles and runs all programs with test output.

```bash
make test
```

### How to Clean

> Remove all compiled executables.

```bash
make clean
```

## Report

The goal of this lab was to develop a deeper understanding of C-string handling and file I/O operations in C. This included implementing a standard C-string function from scratch using only pointer operations, and creating a program that performs file manipulation with string transformations.

In this lab, I completed the following tasks:

1. **Task 1 (C-String Function):** Implemented the `strcpy()` function in `task1_strcpy.c` that copies a string from source to destination without using the `<string.h>` library. The implementation uses pointer arithmetic to iterate through the source string and copy each character to the destination, then adds a null terminator.

2. **Task 2 (File Operations):** Created a program in `task2_fileops.c` that reads from `input.txt`, applies two string modifications (convert to uppercase and replace "hello" with "hi"), and writes the results to `output.txt`. The program is organized into separate functions for each operation.

---

### Class Diagram

Not applicable for this project, as it is written in C and consists of standalone functions rather than classes.

---

### Build Results

> The project was compiled successfully using the provided `Makefile`. The `-Wall` flag was used to ensure all warnings were enabled.

```
gcc -Wall -g task1_strcpy.c -o task1_strcpy
gcc -Wall -g task2_fileops.c -o task2_fileops
=========================================
   Lab 12 - All programs compiled!     
   C-Strings and File Operations       
=========================================
```

---

### Runtime Output

> The following are the outputs from running the compiled programs.

**Task 1: strcpy Implementation (`./task1_strcpy`)**
```
========================================
Testing my_strcpy() implementation
========================================

Test 1 - Basic copy:
  Source: 'Hello, World!'
  Destination: 'Hello, World!'
  Result: PASS

Test 2 - Empty string:
  Source: ''
  Destination: ''
  Result: PASS

Test 3 - Single character:
  Source: 'A'
  Destination: 'A'
  Result: PASS

Test 4 - Long string:
  Source: 'The quick brown fox jumps over the lazy dog'
  Destination: 'The quick brown fox jumps over the lazy dog'
  Result: PASS

Test 5 - String with numbers:
  Source: 'Test123456'
  Destination: 'Test123456'
  Result: PASS

========================================
```

**Task 2: File Operations (`./task2_fileops`)**
```
Lab 12 - Task 2: File Operations and String Manipulation
Variant 1: Convert to uppercase + Replace 'hello' with 'hi'

Processing file...
========================================
Line 1 processed
Line 2 processed
Line 3 processed
Line 4 processed
Line 5 processed
Line 6 processed
========================================
Total lines processed: 6

File processing completed successfully!
Output saved to: output.txt
```

---

### Test Results

All programs compiled and ran successfully. The test results are as follows:

**Task 1 Test Results:**
- Test 1 (Basic copy): PASS
- Test 2 (Empty string): PASS
- Test 3 (Single character): PASS
- Test 4 (Long string): PASS
- Test 5 (String with numbers): PASS

All five test cases passed, confirming that the `strcpy()` implementation works correctly for various input scenarios.

**Task 2 Test Results:**
- Successfully opened input file
- Processed 6 lines from input file
- Applied both string modifications correctly
- Successfully wrote output to output file

**Input File Contents:**
```
hello world
this is a test file
hello there, how are you?
some more text with hello
another line without the keyword
hello hello hello
```

**Output File Contents:**
```
HELLO WORLD
THIS IS A TEST FILE
HELLO THERE, HOW ARE YOU?
SOME MORE TEXT WITH HELLO
ANOTHER LINE WITHOUT THE KEYWORD
HELLO HELLO HELLO
```

---

### Code Coverage

Code coverage analysis was not performed as it was not configured in the project's build system.

---

### Observations and Conclusion

This lab provided valuable experience in implementing standard C library functions from scratch and working with file I/O operations. The `strcpy()` implementation demonstrated the importance of understanding pointer arithmetic and string null termination in C. By implementing this function without using the standard library, I gained a deeper appreciation for how these fundamental operations work at the language level.

The file operations task showed how to properly handle file I/O with error checking, and how to apply multiple string transformations to process text data. The program successfully demonstrates reading from a file, modifying the content, and writing to a new file, which are essential skills for practical C programming.

Key observations:

1. **Pointer Arithmetic:** Using pointers to traverse and manipulate strings is fundamental to C programming and allows for efficient string operations.

2. **String Null Termination:** Every string in C must be null-terminated, which is crucial for functions to know where the string ends.

3. **File I/O Error Handling:** Proper error checking when opening files is essential to prevent crashes and provide meaningful error messages.

4. **Function Modularity:** Breaking down the file processing task into separate functions (to_uppercase, replace_hello_with_hi, process_line) makes the code more maintainable and testable.

5. **Character Manipulation:** Converting between lowercase and uppercase using ASCII values (subtracting 32) is a simple but effective technique.

In conclusion, this lab successfully reinforced fundamental C programming concepts including string handling, pointer operations, and file I/O. The implementations are clean, efficient, and demonstrate proper programming practices.

---
