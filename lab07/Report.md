# **Lab 07 — Unit Testing (Variant 12)**

**Course:** Programming, Part 1 \
**Institution:** NTU KhPI, Kharkiv, Ukraine \
**Student:** Artem Smeliantsev \
**Date:** 16.11.2025

---

## **Task**

Implement expressions as separate user functions (expr1, expr6, expr12, expr16).
Write unit tests for each function using the Unity framework.
Create a Makefile to build:

* the main program
* the static library `libproject.a`
* unit tests (`run_tests`)
* code coverage

---

## **Project Structure**

```
lab07/
├── include/
│   └── lib.h
├── src/
│   └── lib.c
├── test/
│   ├── test_lib.c
│   └── test_main.c
├── Unity/
│   └── src/... (Unity framework)
├── main.c
├── makefile
└── report.md  (this file)
```

---

## **Description of Implemented Functions**

### **expr12(x, y, z, w)**

Expression for Variant 12:

$
(x - \sin(y)) \cdot z^2 + \exp(w)
$

Implemented using `<math.h>` and simple operations (no complex code).

Other expressions (expr1, expr6, expr16) follow the same simple structure, each directly computing its formula.

---

## **Unit Tests**

Each function is tested using Unity:

* known input values
* expected result computed manually
* comparison using:

```
TEST_ASSERT_FLOAT_WITHIN(1e-6f, expected, got);
```

All tests are small and focused on correctness of mathematical calculations.

---

## **Build & Run**

### Build everything

```
make
```

### Run program

```
make run
```

### Run unit tests

```
make test
```

### Clean

```
make clean
```

---

## **Example Test Output**

```
-----------------------
4 Tests 0 Failures 0 Ignored
OK
```

---

## **Code Coverage**

Coverage is generated with:

```
make coverage
```

Output files appear in `coverage_report/`.

---

## **Observations and Conclusion**

The main goal of this lab was to learn how to:

* separate logic into functions
* build a static library
* compile projects using a Makefile
* write and run unit tests
* verify program correctness using automated testing

While implementing the expressions, the most important lesson was learning how to test mathematical functions and control floating-point precision issues.
Switching to float-based Unity assertions ensured stable test behavior without modifying Unity’s internal configuration.

The project builds successfully, all tests pass, and the Makefile supports all required tasks (build, test, run, clean, coverage).
Overall, the lab reinforced the importance of modular design, reproducible builds, and automated testing in real software development.
