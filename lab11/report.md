# Lab 11 — Lab Work Report

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Artem Smeliantsev
**Date:** Dec 04, 2025  

---

## Task Description

This lab focuses on understanding and implementing recursion in C. The tasks were assigned from the `recursion.pdf` document and are based on Variant 12:

1.  **Recursive Calculation:** Calculate the difference between the sum of even and odd digits in a number recursively.
2.  **Recursive Symbol Drawing:** Draw a pyramid that alternates symbols (*, #, +) on each row, with a given height `n`.
3.  **Bonus Task:** Implement an iterative version of the recursive calculation task and compare the execution time of both approaches to analyze their performance.

## Structure

The project is organized into the following file structure:

```text
lab11/
├── Makefile
├── Report.md
├── lab11_task1.c
├── lab11_task2.c
└── lab11_bonus.c
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

### How to Generate Coverage

> Coverage generation is not configured for this project.

### Static Analysis & Formatting

> Static analysis tools like clang-format and clang-tidy are not configured for this project.

## Report

The goal of this lab was to gain practical experience with recursion by solving problems that are well-suited for this technique. This included numerical calculation and graphical pattern generation. A key part of the lab was also to analyze the performance trade-offs between recursive and iterative solutions.

In this lab, I completed the following tasks:

1.  **Task 1 (Calculation):** Implemented a recursive function in `lab11_task1.c` to find the difference between the sum of even and odd digits of an integer. An iterative version was also created to verify the results.
2.  **Task 2 (Drawing):** Wrote a recursive function in `lab11_task2.c` to draw a pyramid of a specified height, with each row using a different symbol (*, #, +) in a cycle.
3.  **Bonus (Performance):** Created a separate program, `lab11_bonus.c`, to measure and compare the execution time of the recursive and iterative digit difference functions over a large number of iterations.

---

### Class Diagram

Not applicable for this project, as it is written in C and consists of standalone functions rather than classes.

---

### Build Results

> The project was compiled successfully using the provided `Makefile`. The `-Wall` flag was used to ensure all warnings were enabled.

```
gcc -Wall -g lab11_task1.c -o lab11_task1
gcc -Wall -g lab11_task2.c -o lab11_task2
gcc -Wall -g lab11_bonus.c -o lab11_bonus
lab11_bonus.c: In function ‘main’:
lab11_bonus.c:102:9: warning: variable ‘dummy_result’ set but not used [-Wunused-but-set-variable]
  102 |     int dummy_result;
      |         ^~~~~~~~~~~~
=========================================
   Lab 11 - All programs compiled!     
           VARIANT 12                   
=========================================
```

---

### Runtime Output

> The following are the outputs from running the compiled programs.

**Task 1: Digit Difference (`./lab11_task1`)**
```
Testing recursive digit difference:
Number:  12345  ->  Difference:  -3  (Odd wins!)
Number:   2468  ->  Difference:  20  (Even wins!)
Number:   1357  ->  Difference: -16  (Odd wins!)
Number:    100  ->  Difference:  -1  (Odd wins!)
Number:    999  ->  Difference: -27  (Odd wins!)
Number:      0  ->  Difference:   0  (It's a tie!)
Number:     42  ->  Difference:   6  (Even wins!)
Number:   -123  ->  Difference:  -2  (Odd wins!)

Number:  12345  ->  Recursive:  -3, Iterative:  -3  ✓
Number:   2468  ->  Recursive:  20, Iterative:  20  ✓
Number:   1357  ->  Recursive: -16, Iterative: -16  ✓
Number:    100  ->  Recursive:  -1, Iterative:  -1  ✓
Number:    999  ->  Recursive: -27, Iterative: -27  ✓
Number:      0  ->  Recursive:   0, Iterative:   0  ✓
Number:     42  ->  Recursive:   6, Iterative:   6  ✓
Number:   -123  ->  Recursive:  -2, Iterative:  -2  ✓

========================================
Breakdown for 12345:
Even digits: 4 2 -> Sum = 6
Odd digits:  5 3 1 -> Sum = 9
Difference: 6 - 9 = -3
========================================

Interactive test - Enter a number: 54321

Breakdown for 54321:
Even digits: 2 4 -> Sum = 6
Odd digits:  1 3 5 -> Sum = 9
Difference: 6 - 9 = -3

Final result: -3
Odd digits are stronger! 
```

**Task 2: Pyramid Drawing (`./lab11_task2`)**
```
========================================
  Pyramid Builder 3000 - Variant 12   
========================================

Pyramid with height 3:
  *
 ###
+++++

Pyramid with height 7:
      *
     ###
    +++++
   *******
  #########
 +++++++++++
*************

========================================
Bonus: Inverted Pyramid
========================================

Inverted pyramid with height 5:
#########
 *******
  +++++
   ###
    *

Interactive mode - Enter pyramid height: 5

Your pyramid with height 5:
    *
   ###
  +++++
 *******
#########
```

**Bonus: Performance Comparison (`./lab11_bonus`)**
```
  Recursive vs Iterative
Test number: 123456789
Iterations: 10000000

Quick verification:
  Recursive result: -5
  Iterative result: -5
 Both methods agree!

Testing RECURSIVE version...
             FINAL RESULTS              
Speed comparison:
  Recursive time: 0.689648 seconds
  Iterative time: 0.585851 seconds

ITERATIVE!
  It's 1.18x faster!
```

---

### Test Results

All programs compiled and ran as expected. The `lab11_task1` program includes a verification step that confirms the recursive and iterative functions produce identical results for a range of test cases, ensuring the correctness of the recursive implementation.

---

### Code Coverage

Code coverage analysis was not performed as it was not configured in the project's build system.

---

### Observations and Conclusion

This lab provided valuable insight into the principles of recursion. The recursive solutions for both the calculation and drawing tasks were elegant and closely mirrored the problem definitions. For example, the pyramid-drawing function naturally breaks the problem down into drawing one row and then recursively calling itself to draw the rest of the pyramid.

The performance comparison in the bonus task highlighted a key trade-off of recursion. Although the recursive function was conceptually simpler, the iterative version performed approximately **1.18x faster**. This is because recursion incurs overhead from repeated function calls, which involves pushing frames onto the call stack. For deep recursion or performance-critical applications, an iterative approach is often superior in terms of both speed and memory usage, as it avoids the risk of stack overflow.

In conclusion, recursion is a powerful tool for solving problems that have a self-similar structure. It can lead to cleaner and more readable code. However, it is essential to be mindful of its performance implications and the potential for stack overflow, and to consider an iterative alternative when performance is a primary concern.

---
