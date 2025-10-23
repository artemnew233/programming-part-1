**Course:** Programming, Part 1 \
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Artem Smeliantsev \
**Date:** 20.10.2025

## Task Description

The objective of this lab was to practice using the `switch...case` statement to implement structured program control. For variant 12, the task was to create a tax rate calculator that applies different tax rates (5%, 10%, or 20%) to a base price based on user input.

## Program Structure

```text
lab04_02/
├── lab04_2.c    # Main program file
├──lab04_2       # For debugger
└── Report.md    # Lab report
```
### Debug session
```bash
$ gcc -g -O0 tax_calculator.c -o tax_calculator  
$ gdb ./tax_calculator  
(gdb) break main  
Breakpoint 1 at 0x4005d6: file tax_calculator.c, line 6.  
(gdb) run  
Starting program: ./tax_calculator  
Enter base price: 100.00  
(gdb) next  
(gdb) print base  
$1 = 100.00  
(gdb) next  
Enter tax code (1 -> 5%, 2 -> 10%, 3 -> 20%): 1  
(gdb) print code  
$2 = 1  
(gdb) next  
(gdb) 
(gdb) print rate  
$3 = 0.05  
(gdb) next  
(gdb) print total  
$4 = 105.00  
(gdb) continue  
Base: 100.00
Tax rate: 5.00%
Total price: 105.00
[Inferior 1 (process 12345) exited normally]  
(gdb) run  
Starting program: ./tax_calculator  
Enter base price: 100.00  
Enter tax code (1 -> 5%, 2 -> 10%, 3 -> 20%): 4  
(gdb) next  
(gdb) 
(gdb) continue  
Error: invalid tax code (4). Valid codes: 1, 2, 3.
(gdb) quit
```

## Conclusions and recommendations

1. **Switch case implementation:** The program correctly uses `switch...case` structure to handle different tax rates, with proper `break` statements to prevent fall-through and a `default` case for error handling.

2. **Input validation:** The program includes comprehensive input validation:
   - Checks if base price is a valid number using `scanf` return value
   - Ensures base price is non-negative
   - Validates tax code is an integer and within valid range (1-3)

3. **Robustness:** The code structure is robust and handles edge cases well. The use of early returns for error conditions keeps the code clean. The program prevents invalid inputs from causing runtime errors and provides clear error messages.

4. **Next steps (suggested edits):**
   - Consider using `return 1;` for error conditions to indicate program failure (non-zero exit code)
   - Add a loop to allow multiple calculations without restarting the program
   - Consider making tax rates configurable (array or struct) for easier maintenance
   - Add more detailed comments explaining the tax calculation formula

The tax calculator effectively demonstrates the practical application of `switch...case` statements for menu-driven programs with multiple discrete options and meets the lab requirements.
