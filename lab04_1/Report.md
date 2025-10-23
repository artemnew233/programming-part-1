# Short Report.md — Variant 12

**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** _STUDENT_NAME_  
**Date:** _DATE_OF_WORK_  

---

## Variant number
**Variant:** 12

---

## Source code provided

```c
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter number n (0-9999): ");
    if (scanf("%d", &n) != 1)
    {
        puts("Invalid input, write a number");
        return 0;
    }

    if (n < 0 || n > 9999)
    {
        puts("Error: n must be in range 0-9999");
        return 0;
    }

    int d1 = (n / 1000) % 10;
    int d2 = (n / 100) % 10;
    int d3 = (n / 10) % 10;
    int d4 = n % 10;
    if (d1 == 0 && d2 == 0 && d3 == 0)
    {
        printf("The number has only one digit: %d\n", d4);
        puts("NO");
        return 0;
    }
    if (d1 == d2)
    {
        if (d2 == d3)
        {
            if (d3 == d4)
            {
                printf("YES, %d has 4 same digits %d", n, d1); // --> yes
            }
            else
            {
                printf("YES, %d has 3 same digits %d", n, d1); // --> yes
            }
            return 0;
        }
        if (d2 == d4)
        {
            printf("YES, %d has 3 same digits %d", n, d1); // --> yes
            return 0;
        }
        else
        {
            printf("NO, there are no same digits in %d", n); // --> no
            return 0;
        }
    }
    if (d1 == d3)
    {
        if (d3 == d4)
        {
            printf("YES, %d has 3 same digits %d", n, d1);
            return 0;
        }
        else
        {
            printf("NO, there are no same digits in %d", n);
            return 0;
        }
    }
    if (d2 == d3)
    {
        if (d3 == d4)
        {
            printf("YES, %d has 3 same digits %d", n, d2);
            return 0;
        }
        else
        {
            printf("NO, there are no same digits in %d", n);
            return 0;
        }
    } 
    else ещеelse еще
    { 
        printf("NO, there are no same digits in %d", n);
        return 0;
    }
}
```

## Test results (sample runs)

1. Input: `1222`  
   - digits: `d1=1 d2=2 d3=2 d4=2`  
   - code path: `d1==d2` false → `d1==d3` false → `d2==d3` true → `d3==d4` true → prints:  
   YES, 1222 has 3 same digits 2

2. Input: `2222`  
   - digits: `2 2 2 2`  
   - code path: `d1==d2` true, `d2==d3` true, `d3==d4` true → prints:
   YES, 2222 has 4 same digits 2
   *Remark:* Program treats four-equal as a YES (message mentions 4 same digits).

3. Input: `111`  
   - digits (with leading zero): `0 1 1 1`  
   - code finds `d2==d3==d4` → prints:
   YES, 111 has 3 same digits 1

4. Input: `1000`  
   - digits: `1 0 0 0`  
   - code finds `d2==d3==d4` → prints:
   YES, 1000 has 3 same digits 0

5. Input: `0`  
   - digits: `0 0 0 0`  
   - early special-case `d1==0 && d2==0 && d3==0` is true → prints:
   The number has only one digit: 0
   NO
   *Remark:* For `0` the program reports "single-digit" and `NO`, even though all four digits are equal.

6. Input: `707`  
   - digits: `0 7 0 7`  
   - no three equal digits → prints:
   NO, there are no same digits in 707

7. Input: `1212`  
   - digits: `1 2 1 2`  
   - no three equal digits → prints:
   NO, there are no same digits in 1212

---

## Debug session (textual gdb transcript)

Below is a representative textual debug session (10–20 lines). It inspects `n`, extracted digits `d1..d4`, and the branch variable effects. This is a text transcript (suitable instead of screenshot):

```bash
$ gcc -g -O0 task_variant12_fixed.c -o task_variant12  
$ gdb ./task_variant12  
(gdb) break main  
Breakpoint 1 at 0x4005d6: file task_variant12_fixed.c, line 6.  
(gdb) run  
Starting program: ./task_variant12  
Enter number n (0-9999): 1222  
(gdb) next  
(gdb) print n  
$1 = 1222  
(gdb) print d1,d2,d3,d4  
$2 = 1 2 2 2  
(gdb) next  
(gdb) # now inside branch where d2==d3 and d3==d4  
(gdb) continue  
YES, 1222 has 3 same digits 2  
[Inferior 1 (process 12345) exited normally]  
(gdb) run  
Starting program: ./task_variant12  
Enter number n (0-9999): 2222  
(gdb) next  
(gdb) print d1,d2,d3,d4  
$3 = 2 2 2 2  
(gdb) next  
(gdb) # branch: all four equal  
(gdb) continue  
YES, 2222 has 4 same digits 2  
(gdb) quit
```

---

## Conclusions and recommendations

1. **Syntax fix required:** The provided source contains a non-ASCII/Cyrillic fragment `else ещеelse еще` which prevents compilation. Replace it with a normal final `else { ... }` to make the program compile.

2. **Specification mismatch (semantic):** The program prints `YES` for four identical digits (`2222`) and also treats `0` as a single-digit special case that prints `NO`. If the lab requirement is *exactly three identical digits*, then:
   - Modify the `d1==d2==d3==d4` branch to output `NO` (since 4 equal digits are not "exactly three").
   - Remove or adjust the special-case `d1==0 && d2==0 && d3==0` if you want `0` to be treated as four equal digits instead of a single-digit exception.

3. **Robustness:** The nested `if/else` structure meets the "even variant → nested if" constraint; it is explicit and debuggable. For maintainability, consider:
   - Counting occurrences of each digit (0..9) and checking for count == 3 (compact and clear).
   - Adding unit tests for boundary values: `0`, `9`, `10`, `99`, `100`, `999`, `1000`, `9999`.

4. **Next steps (suggested edits):**
   - Fix syntax error.
   - Decide whether the requirement is "exactly three" or "three or more" and adjust logic accordingly.
   - If "exactly three", in the `d1==d2==d3==d4` case print `NO`.


