# Lab 03_01 — Lab Work Report (Variant 9)

---

**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Artem Smeliantsev  
**Date:** 2025-10-19

---

## Task (short)

Implement a C program that evaluates the arithmetic expression for a single input `x`, prints intermediate variables for debugging, and detects invalid inputs (zero denominators). Provide a debug session (or screenshot) showing intermediate values.

---

## Variant number and formula

**Variant:** 9

**Formula**  
**9.** \( E(x) = \dfrac{x^2 - 25}{x - 5} + \dfrac{3(4x + 1)}{x + 2} \)
![alt text](image.png)

---

## Files

- [`task3_1.c`](task3_1.c) # source file implementing Variant 9
- and a lot of screenshots

---

## How to build / run

```bash
# compile
gcc -g -O0 -Wall -lm task3_1.c -o task3_1

# run
./task3_1
# program will prompt: Enter x:
```

example: \
![alt text](image-1.png)

---

## Sample runtime output (3+ values)

### Example 1 — `x = 0`

```
Enter x: 0
E(0.000000) = 6.500000
```

![alt text](image-2.png) => output \
![alt text](image-3.png) => debug  

### Example 2 — `x = 2`

```
Enter x: 2
E(2.000000) = 13.750000
```

![alt text](image-4.png) => output \
![alt text](image-5.png) => debug

### Example 3 — `x = 4.9` (near singularity)

```
Enter x: 4.9
E(4.900000) = 18.856522
```

![alt text](image-6.png) => output \
![alt text](image-7.png) => debug

### Undefined cases

```
Enter x: 5
E(5.000000) = -nan
```

![alt text](image-8.png) => output \
![alt text](image-9.png) => debug

```
Enter x: -2
E(-2.000000) = -inf
```

![alt text](image-10.png) => output \
![alt text](image-11.png) => debug

---

## Debugger screenshot

![alt text](image-12.png)

---

### Observations and Conclusion

> While running the program I observed the following behavior and results.

- When I entered `0`, the program printed `E(0.000000) = 6.500000`.  
    (Calculation seen: `(-25)/(-5) = 5` and `3*(1)/2 = 1.5`, total `6.5`.)

- When I entered `2`, the program printed `E(2.000000) = 13.750000`.  
    (`(-21)/(-3) = 7` and `27/4 = 6.75`, total `13.75`.)

- When I entered `4.9` (close to 5), the program printed `E(4.900000) ≈ 18.856522`.  
    I noticed the result changes quickly for small changes in `x` near `5` — the expression is highly sensitive there.

- When I entered `5`, the program attempted to divide by zero in the first term (`x-5 = 0`); the result became infinite/undefined (`inf` or `nan` depending on the runtime), i.e. the program produced an undefined numeric result.

- When I entered `-2`, the program attempted to divide by zero in the second term (`x+2 = 0`); similarly, the result became infinite/undefined.

- I observed that the program prints only the final value `E(x)` and does not display intermediate variables (`a`, `b`, `c`, `d`, `e`) during normal runs.

- I entered a non-numeric string to test input handling: `scanf` accepted nothing meaningful and the program did not detect malformed input (no error message appeared).

- I also noticed `math.h` is included but no math functions from it are used in this code as executed.

**Conclusion:** Running the program shows correct numeric outputs for ordinary inputs, rapid growth and sensitivity of the result near `x = 5`, and undefined/infinite outcomes when `x = 5` or `x = -2`. The program does not report intermediate values or input-read errors during these runs.
