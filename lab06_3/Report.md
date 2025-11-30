**Course:** Programming, Part 1 \
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Smeliantsev Artem  
**Date:**  1 November 2025  
---

## Task Description

Implement a small library that prints values computed by a callback function for an integer range. Provide a simple demo `main.c`, build system (Makefile), and a short report.

Variant implemented: **12 — `print_table`**
Function prototype implemented:
`void print_table(int from, int to, double (*f)(int));`

---

## Project structure (relevant)

```
lab06_03/
├── include/
│   └── callbacks.h
├── src/
│   └── callbacks.c
├── main.c
├── Makefile
└── Report.md    # this file
```

---

## How to build / run

```bash
# build (default target)
make

# build and run the app
make run

# alternatively, run the built executable directly
./build/app
```

(If you added the ARGS variant to `run`, you can pass arguments: `make run ARGS="..."` — not needed here.)

---

## Implemented files (short description)

* `include/callbacks.h` — typedef for the callback and `print_table` declaration.
* `src/callbacks.c` — implementation of `print_table`: iterates `i` from `from` to `to` and prints `i -> f(i)`; does nothing if `f == NULL` or `from > to`.
* `main.c` — demo program with several sample callbacks (`identity`, `square`, `recip_plus_one`) and example calls including edge cases.
* `Makefile` — builds object files in `build/` and produces `build/app`; contains `run` target that builds and executes.

---

## Build results

Command:

```
make
```

Expected result:

* Objects compiled into `build/` and `build/app` created without warnings (with `-Wall -Wextra`).
* No runtime link errors. (See runtime output below.)

---

## Runtime output (sample)

Output from `make run` / `./build/app`:

```
print_table(1, 5, identity):
1 -> 1.000000
2 -> 2.000000
3 -> 3.000000
4 -> 4.000000
5 -> 5.000000

print_table(-2, 2, square):
-2 -> 4.000000
-1 -> 1.000000
0 -> 0.000000
1 -> 1.000000
2 -> 4.000000

print_table(0, 4, recip_plus_one):
0 -> 1.000000
1 -> 0.500000
2 -> 0.333333
3 -> 0.250000
4 -> 0.200000

Edge cases (no output expected):
```

Notes:

* Calls with `from > to` produce no output.
* Calls with `f == NULL` produce no output.


---

## Code coverage / Static analysis

* No coverage tooling configured for this small demo.
* The code compiles with `-Wall -Wextra`; no warnings expected for the provided sources when compiled with the supplied Makefile settings.

---

## Observations and Conclusion

* `print_table` is intentionally simple and generic: it accepts a user-supplied function `double (*f)(int)` so the same printer supports arbitrary integer→double mappings (identity, polynomial, reciprocal, trig wrappers, etc.).
* During runs I observed correct formatted output for positive and negative ranges, and correct behavior for edge cases:

  * When `from > to` there is no output (function returns immediately).
  * When the callback pointer is `NULL` there is no output (safe no-op).
* The separation into header (`include/`) and implementation (`src/`) and producing object files in `build/` keeps the project tidy and matches typical C project layout.
* **Conclusion:** The `print_table` variant (12) is implemented and behaves as required: it is robust for the intended use (printing numeric results for integer indices), demonstrates callback usage clearly, and the demo program provides representative examples and edge-case checks.

