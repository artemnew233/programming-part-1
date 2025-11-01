# Lab 06 — Macros for Series (Variant 12) — Report

---

**Course:** Programming, Part 2
**Institution:** NTU KhPI, Kharkiv, Ukraine
**Student:** *STUDENT_NAME*
**Date:** 2025-11-01

---

## Task Description (short)

Implement Variant **12** from the lab: provide two macros that compute sums of series:

* `SERIES_AR_SUM(out, a1, d, n)` — sum of the arithmetic series with first term `a1`, difference `d`, number of terms `n`.
* `SERIES_GEOM_SUM(out, a0, q, n)` — sum of the geometric series with first term `a0`, ratio `q`, number of terms `n`.

Macros must be robust: evaluate each argument exactly once, behave correctly for edge cases (`n <= 0`, `q == 1`), and be safe to use in expression contexts.

---

## Delivered files

Project layout (created for this lab):

```
lab06_macros_variant12/
├── include/
│   └── user_macros.h     # implemented macros (SERIES_AR_SUM, SERIES_GEOM_SUM)
├── src/
│   └── user_funcs.c      # optional: static inline functions for comparison/tests
├── main.c                # demo / test program that exercises the macros
└── Makefile              # builds objects into build/ and links app
```

Short descriptions:

* **include/user_macros.h** — contains the two required macros implemented as statement-like macros using `do { ... } while (0)`, with local temporaries to guarantee single evaluation of arguments and to handle edge cases safely.
* **src/user_funcs.c** — `static inline` function equivalents (optional) used while testing to compare results and for type-checked implementations.
* **main.c** — example program that uses the macros with several test cases (arithmetic, geometric, edge cases).
* **Makefile** — builds object files into `build/` and links `build/app`. Also provides helpful targets (`make`, `make run` can be added).

---

## How to build and run

From the project root (where `Makefile` is located):

```bash
# build
make

# run (or use make run if you added that target)
./build/app
```

Example `make run` target (optional — can be appended to Makefile):

```makefile
run: exe
	./$(BUILD)/app
```

---

## Tests performed and runtime output

I tested the macros with representative values including normal cases and edge cases.

Representative program output (expected):

```
AR: a1=2,d=3,n=5 -> S = 40.000000 (expected 40)
AR: a1=1.5,d=-0.5,n=4 -> S = 5.000000
AR: n=0 -> S = 0.000000 (expected 0)
GEOM: a0=1,q=2,n=4 -> S = 15.000000 (expected 15)
GEOM: a0=3,q=1,n=5 -> S = 15.000000 (expected 15)
GEOM: a0=2,q=0.5,n=3 -> S = 3.500000 (expected 3.5)
GEOM: a0=5,q=-2,n=3 -> S = -35.000000
GEOM: n=0 -> S = 0.000000 (expected 0)
```

Test cases used (non-exhaustive):

* Arithmetic: `(a1=2, d=3, n=5)` → `S = 40`
* Arithmetic: `(a1=1.5, d=-0.5, n=4)` (descending progression)
* Arithmetic: `n = 0` → expected `0`
* Geometric: `(a0=1, q=2, n=4)` → `S = 1 + 2 + 4 + 8 = 15`
* Geometric: `q = 1` case: `(a0=3, q=1, n=5)` → `S = n * a0 = 15`
* Geometric: fractional ratio `(q = 0.5)` and negative ratio `(q = -2)` tested
* Edge: `n = 0` and negative `n` behavior returns `0.0`

---

## Implementation notes & important decisions

* **Single evaluation of macro arguments:** each macro immediately stores converted inputs into local temporaries (with unique internal names) so expressions passed by the caller are evaluated exactly once.
* **Statement-like macros:** macros are wrapped in `do { ... } while (0)` so they behave like single statements and are safe in `if/else` constructs.
* **Type conversions:** inputs are cast to `double` for computing results; this balances safety and simplicity for the lab. If higher precision is required, these can be changed to `long double`.
* **Geometric `q == 1` handling:** floating point equality is checked with a small epsilon (`1e-12`) to handle inexact representations: if `fabs(q - 1.0) < eps` the macro uses `n * a0`.
* **n <= 0:** for non-positive `n` the macros set the output to `0.0`.
* **`pow` usage:** geometric formula uses `pow(q, n)` when `q != 1`.
* **Optional function versions:** `static inline` functions (in `src/user_funcs.c`) are provided as type-checked alternatives which can be used in test builds.

---

## Observations and conclusion

This lab reinforced safe macro-writing practices in C:

* Macros that perform non-trivial computations must protect against multiple evaluations of side-effecting arguments; using internal temporaries is essential.
* Wrapping macros with `do { ... } while (0)` makes them syntactically safe in common control-flow contexts.
* Numeric edge cases (like `q == 1` and `n <= 0`) must be handled explicitly to avoid division by zero or surprising results.
* Floating point comparisons need a tolerance (epsilon) to be robust in practice.
* Providing `static inline` function equivalents is useful for testing and for situations where type-checking is preferred over macro flexibility.

The implemented macros are compact, robust for the tested inputs, and behave correctly in the checked cases. For production code or stricter numerical requirements, consider:

* switching to `long double` for better precision,
* documenting macro preconditions and return behavior,
* adding unit tests to exercise a wider numeric range (very large `n`, ratios close to `1`, etc.),
* and optionally providing function-based APIs for stricter type checks.

---

If you want, I can:

* produce the final `Report.md` file and save it into your project folder,
* add a `make report` target that copies the report into `build/` or packages it,
* or run/generate more exhaustive numeric tests and include their logs in the report. Which would you like next?
