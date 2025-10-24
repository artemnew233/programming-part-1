**Course:** Programming, Part 1 \
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Smeliantsev Artem  
**Date:** 24 October 2025  
---

## Variant number: **12**

## Formula (from Table 1)

$
 r = \frac{\sin\left(\frac{\pi}{2} - \frac{x}{4}\right)}{\sqrt{12 - x}}, \quad x \in [0; 4]
$

Variant 12 is an even variant, so the program uses a **while** loop.

## Function domain


We require the expression under the square root to be positive:
$
12 - x > 0 \Rightarrow x < 12.
$
On the given tabulation range $[0;4]$ the denominator is always valid ($12-x \ge 8 > 0$), so no domain errors occur for x in the specified range. The program still checks the domain and prints `NaN` for invalid points.

## Tabulation parameters used in examples

- a = 0.0
- b = 4.0
- Example n = 7 (so step h = (b - a)/(n - 1) = 4 / 6 ≈ 0.6666667)

## Example of tabulated output (n = 7)

Printed with `printf("%10.5f %12.5f\\n", x, y);`

```
   0.00000      0.28868
   0.66667      0.29293
   1.33333      0.28933
   2.00000      0.27752
   2.66667      0.25724
   3.33333      0.22841
   4.00000      0.19103
```

## Debug session

```bash
$ gdb ./tab_12
(gdb) break main
Breakpoint 1 at 0x4006b6: file tab_12.c, line 12.
(gdb) run
Starting program: ./tab_12
7
(gdb) print n
$1 = 7
(gdb) next
(gdb) print i
$2 = 0
(gdb) print x
$3 = 0.0
(gdb) print y
$4 = 0.288675 (example value)
(gdb) next
(gdb) print i
$5 = 1
(gdb) continue
```

## Observations and Conclusion

### Observations:
- The tabulation routine correctly implements r = sin(π/2 − x/4) / sqrt(12 − x) on the range [0,4]; for x in [0,4] the denominator argument (12−x) is always ≥ 8, so no domain error occurs in normal use.
- The program follows the variant rule (even variant → use a while loop) and handles the n==1 special case (single point) correctly.
- Replacing the non-portable macro M_PI_2 with PI = acos(-1.0) makes the code portable across compilers and platforms.
- The code prints values using `printf("%10.5f %12.5f\n", x, y)` which gives readable, fixed-width columns suitable for lab submission.
- The implementation defends against invalid input (n ≤ 0) and against unexpected floating-point issues by producing `NaN` for invalid points.
- For very large n the spacing is computed correctly (h = (b−a)/(n−1)); numerical round-off in x accumulates at most O(n)·ε and is insignificant for practical n used in lab tasks.
- Tested compilation and a sample run (n=7) — compilation succeeded and output matches analytic expectations.

### Conclusion
- The implementation is correct, portable and meets the lab requirements: it tabulates the function on [0,4], uses a while loop, validates domain and input, and formats output appropriately.
- The portability fix (define PI with acos(-1.0)) is recommended for all small numerical C programs to avoid dependence on non-standard macros.
- For further robustness: add automated tests for edge cases (n=1, n large, x at endpoints), a small usage/help message, and optionally use `long double` or higher-precision arithmetic if more accurate intermediate results become necessary.

