# Lab 05_03 — Base Conversion (Variant 12) — Minimal headers

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _STUDENT_NAME_  
**Date:** 24 October 2025  

---

## Variant number

**12** — bases (a, b) = **(5, 10)**

## Example inputs and outputs

Example interactive run (user input shown after prompts):

```
Base-5 -> Decimal conversion
Enter base-5 number (digits 0..4), then Enter: 1324
Decimal result: 214

Decimal -> Base-5 conversion
Enter decimal (unsigned) number, then Enter: 214
Base-5 result: 1324
```

## Debug session (GDB-style, sample)

```bash
$ gdb ./base5_12_minimal
(gdb) break main
(gdb) run
Starting program: ./base5_12_minimal
1324
(gdb) print v
$1 = 0
(gdb) next
(gdb) print ch
$2 = 49 '1'
(gdb) next
(gdb) print v
$3 = 1
(gdb) next
(gdb) print ch
$4 = 51 '3'
(gdb) next
(gdb) print v
$5 = 8
(gdb) continue
# After conversion printed: Decimal result: 214
(gdb) next
# Now enter decimal input
214
(gdb) print n
$6 = 214
(gdb) next
(gdb) print p
$7 = 125
(gdb) next
(gdb) print d
$8 = 1
(gdb) continue
# Final printed Base-5 result: 1324
```

## Observations and Conclusion

```
Observations and Conclusion

Observations
- The program successfully converts between base-5 and decimal using only <stdio.h> and <ctype.h>.
- Using (unsigned long long)(-1) to obtain the maximum unsigned value is a portable trick that avoids including <limits.h>.
- The code adheres to the constraints: no arrays, no user-defined functions, and only multiplication/division used for the conversions.
- Input validation for base-5 digits is performed; invalid digits cause an error and the program exits.
- Overflow detection is implemented and will report `OVERFLOW while converting base-5 to decimal` if the input is too large for unsigned long long.

Conclusion
- The minimal-header implementation is correct and portable for typical lab inputs. It keeps the code simple and meets the assignment requirements.
- For extremely large numbers or production-grade conversion, consider arbitrary-precision libraries (e.g., GMP) or use a string-based algorithm with big-integer arithmetic.
```
