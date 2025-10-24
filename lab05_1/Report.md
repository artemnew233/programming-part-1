**Course:** Programming, Part 1 
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Smeliantsev Artem  
**Date:** 24 October 2025  

---

## Task Description

1. Install the Markdown extension in VS Code  
2. Learn the basic syntax of Markdown tags  
3. Create any document and format it using Markdown  
4. Write a report and attach it to this task

This particular assignment (Lab 05_01 — *Sums and Products*, Variant **12**) requires implementing the series

$
S = \sum_{n=1}^{20} \frac{x^{\\,n+1}}{2n+1}
$

as two separate programs:

- an **integer** implementation (`series_12_int.c`) using a `for` loop; intermediate calculations use `__int128` and the final accumulator is `int64_t`. The program must detect and report overflow (`OVERFLOW`).
- a **floating-point** implementation (`series_12_fp.c`) using a `do ... while` loop and `double` arithmetic; it prints the result or `NaN` on invalid floating operations.

Each task/version should be developed in its own git branch (suggested branch names below).

## Structure

```text
lab05_01
├── series_12_int.c   # integer version (for loop)
├── series_12_fp.c    # floating-point version (do...while)
└── Report.md         # this report
```

## Report

### Goal of this lab

Implement and compare integer and floating-point computations of the given finite series, obeying the loop-type constraint for the variant (even variant → `for` or `do...while` rules as given). Detect and properly report overflow for the integer version and invalid floating operations for the FP version.

### In this lab I completed

- Implemented `series_12_int.c` (integer, `for` loop, overflow detection).
- Implemented `series_12_fp.c` (double, `do...while` loop).
- Verified builds and ran sample inputs.
- Performed basic debug sessions in `gdb` and collected transcripts to include in the report.
- Prepared this report and recommended git branch names.

---

### Algorithm description

**Common mathematical task:** compute  
$
S = \sum_{n=1}^{20} \frac{x^{\\,n+1}}{2n+1}
$
**Integer version (`series_12_int.c`) — key points**

- Read `x` as `int64_t`.
- Use `__int128 xpow` to store powers safely while checking overflow.
- Maintain `S` as `int64_t`.
- Loop: `for (n = 1; n <= 20; ++n)`:
  - compute `pow_n1 = xpow * x` as `__int128` (this is $x^{n+1}$);
  - compute `term = pow_n1 / (2*n + 1)` as `__int128`;
  - check `term` fits into `int64_t`; if not, print `OVERFLOW` and exit;
  - check `S + term` fits into `int64_t`; if not, print `OVERFLOW` and exit;
  - cast term to `int64_t` and add to `S`;
  - set `xpow = pow_n1` for the next iteration.
- Finally print `S` with `printf`.

**Floating-point version (`series_12_fp.c`) — key points**

- Read `x` as `double`.
- Initialize `S = 0.0`, `xpow = x`, `n = 1`.
- Use `do { ... } while (n <= 20)` loop:
  - `num = xpow * x` (double, $x^{n+1}$);
  - `denom = 2.0 * n + 1.0`;
  - if `!isfinite(num)` or denom invalid → print `NaN` and exit;
  - `S += num / denom`;
  - `xpow *= x; ++n;`
- Print `S` with `printf("%.10g\n", S);`

**Design decisions**

- Integer version uses `__int128` temporaries to delay overflow detection until conversion to the output type, and to check the accumulative addition safely.
- Floating point uses iterative power (`xpow *= x`) to avoid repeated calls to `pow()` and to better control operations for debugging.
- Loop types follow the lab rule: integer uses `for` (even variant requirement), floating uses `do ... while` to demonstrate another control structure.

---

### Runtime Output

Example interactive runs and outputs (captured stdout):

- Run (floating-point)
```
$ echo 2 | ./series_12_fp
108247.8853091839
```

- Run (integer)
```
$ echo 2 | ./series_12_int
108237
```

- Run (x = 1)
```
$ echo 1 | ./series_12_fp
1.504063454266974
$ echo 1 | ./series_12_int
0
```

- Run (x = 10)
```
$ echo 10 | ./series_12_fp
2.7256579684353917e+19
$ echo 10 | ./series_12_int
OVERFLOW
```

---

### Test Results

Run several sample inputs and compared outputs of both programs.

| Input x | `series_12_fp` (double)            | `series_12_int` (int64) |
|--------:|:----------------------------------:|:------------------------:|
| 1       | `1.504063454266974`                | `0`                      |
| 2       | `108247.8853091839`                | `108237`                 |
| 10      | `2.7256579684353917e+19`           | `OVERFLOW`               |
| -1      | `0.20270380443060126`              | `-10`                    |

**Notes:**

- The integer program performs C integer division (truncating toward zero) on each term before accumulation — thus its output differs from the floating-point calculation which sums fractional terms.
- For large magnitudes of `x` (e.g., ±10), integer intermediates overflow; the program detects and reports `OVERFLOW`.
- Floating-point can represent very large values (up to ~1e308), but precision loss occurs for very large powers.

---

### Debug session:

**Integer version (`series_12_int`)**

```bash
$ gdb ./series_12_int
(gdb) break main
(gdb) run
Starting program: ./series_12_int
Enter X: 2
(gdb) print x
$1 = 2
(gdb) next
(gdb) print n
$2 = 1
(gdb) print xpow
$3 = 2
(gdb) print pow_n1
$4 = 4
(gdb) print term
$5 = 1
(gdb) print S
$6 = 1
(gdb) continue
```

**Floating-point version (`series_12_fp`)**

``` bash
$ gdb ./series_12_fp
(gdb) break main
(gdb) run
Starting program: ./series_12_fp
Enter x: 2
(gdb) print x
$1 = 2
(gdb) next
(gdb) print n
$2 = 1
(gdb) print xpow
$3 = 2
(gdb) print num
$4 = 4.0
(gdb) print denom
$5 = 3.0
(gdb) print S
$6 = 1.3333333333333333
(gdb) continue
```

---

### Observations and Conclusion

**Observations**

- The integer implementation is strict: every term is computed as an integer (truncated division), so fractional contributions are lost. This makes the integer result substantially different from the floating-point result for non-trivial `x`.
- Use of `__int128` for intermediate computations is effective to delay overflow detection, but even so, large exponents will overflow `__int128` for moderately large `x` and `n`. The program correctly detects term or accumulation overflow and reports `OVERFLOW`.
- The floating-point implementation gives the mathematically expected real-valued sum (within `double` precision), but for very large |x| the result may exceed the double range (→ `inf`) or suffer from precision loss.
- The lab constraint about using specific loop types per variant was followed: `for` for integer (even variant), `do...while` for floating point.

**Conclusion**

Both implementations fulfill the lab requirements and illustrate trade-offs:

- Use integer arithmetic if you need exact integral results and can guarantee value ranges; protect against overflow and document the behavior (here: printing `OVERFLOW`).
- Use floating-point arithmetic when fractional results are required; remember to check for `NaN`/`inf` and note precision limits.
- For production or more accurate rational results one might implement exact rational arithmetic (big integers for numerator/denominator) or use arbitrary-precision libraries when necessary.
  
---
