**Course:** Programming, Part 1 \
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Smeliantsev Artem  
**Date:**  1 November 2025  

---

## Variant

**12** — implement two functions: geometric and arithmetic series sums.

## Task (short)

Implement two functions without arrays or helper functions and demonstrate them from `main.c`:

- `double series_geom(double a0, double q, unsigned n)` — sum of n terms of geometric progression.
- `double series_arith(double a1, double d, unsigned n)` — sum of n terms of arithmetic progression.

Project layout (used for this submission):

```text
lab06_01/
├── include/
│   └── user_funcs.h   # function prototypes
├── src/
│   └── lab06_1.c      # implementations
├── main.c             # demo / driver program
├── makefile           # builds build/app, provides 'make run'
└── report.md
````

## Implementation notes

* Both functions are implemented iteratively (no `pow`, no arrays) in `src/lab06_1.c`.
* `main.c` reads input (two lines or interactively), calls the functions and prints results.
* `makefile` (lowercase) uses a `vpath`-based pattern rule and places object files into `build/`. The linked executable is `build/app`.
* A convenience target `make run` builds and runs `./build/app`.

## How to build & run

Build:

```bash
make
```

Run (convenience):

```bash
make run
```

Or run directly after building:

```bash
./build/app
```

Non-interactive example (two inputs piped):

```bash
# first line: a0 q n  (geometric)
# second line: a1 d n (arithmetic)
echo -e "2 0.5 5\n3 2 4" | ./build/app
```

## Sample runtime output

```
Geometric series (variant 12): S_n = a0 + a0*q + ... (n terms)
Enter a0 q n  (example: 2 0.5 5): 2 0.5 5
series_geom(2, 0.5, 5) = 3.875

Arithmetic series: S_n = a1 + (a1+d) + ... (n terms)
Enter a1 d n  (example: 3 2 4): 3 2 4
series_arith(3, 2, 4) = 24
```

## Debug session (short GDB transcript)

Example steps to inspect `series_geom` internals (10–15 lines):

```bash
$ gdb ./build/app
(gdb) break series_geom
Breakpoint 1 at 0x4010f0: file src/lab06_1.c, line 10.
(gdb) run
Starting program: ./build/app
2 0.5 5
# program stops at series_geom entry
(gdb) print a0
$1 = 2.0
(gdb) print q
$2 = 0.5
(gdb) print n
$3 = 5
(gdb) next
(gdb) print term
$4 = 2.0
(gdb) print sum
$5 = 0.0
(gdb) continue
```

Include an actual transcript / screenshot from your environment when submitting.

## Test cases (checked)

* Geometric: `a0=2, q=0.5, n=5` → `3.875` (2 + 1 + 0.5 + 0.25 + 0.125).
* Geometric: `a0=1, q=1, n=10` → `10` (handled by iteration).
* Arithmetic: `a1=3, d=2, n=4` → `24` (3 + 5 + 7 + 9).
* Edge case: `n=0` → functions return `0.0`.

## Observations and conclusion

* The iterative approach meets the lab constraints and is straightforward to test and debug.
* Placing compilation outputs in `build/` keeps the project directory clean; the `make run` target simplifies testing.
* For very large `n` or extreme `q`, floating-point overflow/underflow may occur — this is a limit of `double`, not the algorithm.

**Conclusion:** Implementation for Variant 12 is complete and tested. The provided `makefile` builds `build/app` and `make run` executes the program — this workflow is convenient for grading and demonstration.

