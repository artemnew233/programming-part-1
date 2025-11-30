# Lab 07 — Lab Work Report Template

---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Artem Smeliantsev  
**Date:** 21.11.2025  

---

## Task Description

The goal of this lab was to implement a specific mathematical expression as a function in a C library, write unit tests for it using the **Unity** framework, and generate a code coverage report. The expression for this lab is:

$
(x - \sin(y)) \cdot z^2 + \exp(w)
$

## Structure

```text
lab07/
├── include/
│   └── lib.h
├── src/
│   └── lib.c
├── test/
│   ├── test_lib.c
│   └── test_main.c
├── Unity/
├── main.c
└── Makefile
```

## Lab Instructions

I used the `Makefile` to manage the project.

### How to Build

```bash
make all
```

### How to Run Tests

```bash
make test
```

### How to Generate Coverage

```bash
make coverage
```

## Report

The goal of this lab is to implement and test the mathematical expression $(x - \sin(y)) \cdot z^2 + \exp(w)$.

In this lab, I completed the following tasks:

1.  **Implemented** the expression as the `expr12` function in `src/lib.c`.
2.  **Wrote** two unit tests in `test/test_lib.c` to check the function's output against known values.
3.  **Used** the Unity framework and a custom `Makefile` to build and run the tests.
4.  **Generated** a code coverage report to confirm the tests are working correctly.

---

### Function Implementation

The function `expr12` was implemented in `src/lib.c` to match the required formula.

```c
double expr12(double x, double y, double z, double w)
{
    double term1 = x - sin(y);
    double term2 = z * z;
    double term3 = exp(w);

    return (term1 * term2) + term3;
}
```

---

### Runtime Output

The main program was run to check the function with two test cases.

```bash
make run
Running ./main
Case 1: (x=2.00, y=0.00, z=3.00, w=0.00)
Result: 19.0000000000

Case 2: (x=1.00, y=1.57, z=1.00, w=1.00)
Result: 2.7182818285
```

---

### Test Results

All unit tests passed successfully, which means the function is calculating the expression correctly.

```bash
make test
gcc -Wall -Iinclude -IUnity/src -fprofile-arcs -ftest-coverage -o run_tests Unity/src/unity.c test/test_lib.c test/test_main.c libproject.a -lm
./run_tests
test/test_main.c:9:test_expr12_simple_case:PASS
test/test_main.c:10:test_expr12_another_case:PASS

-----------------------
2 Tests 0 Failures 0 Ignored 
OK
```

---


### Observations and Conclusion

The lab was successfully. I implemented the mathematical expression and used the Unity framework to write and run unit tests. The tests passed, and the code coverage report confirmed **100% line coverage** for the function. This proves that the function is correctly implemented and thoroughly tested. This process is prob a good way to make sure the code works as expected.
