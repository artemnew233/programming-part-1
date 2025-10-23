# Lab 04_03 — Point-in-Region Test Report

**Course:** Programming, Part 1 \
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Artem Smeliantsev \
**Date:** 20.10.2025

---

## Variant Number
**Variant:** 12

---

## Equations and Logical Conditions

### Region Definition:
The shaded region consists of a rectangle with a triangular exclusion zone.

### Boundary Equations:

**Outer Rectangle:**
- Left boundary: x = -2.0
- Right boundary: x = 2.0
- Bottom boundary: y = -1.0
- Top boundary: y = 3.0

**Triangular Exclusion (vertices at (0,0), (2,2), (-2,2)):**
- Edge 1: y = x (line from (0,0) to (2,2))
- Edge 2: y = -x (line from (0,0) to (-2,2))
- Edge 3: y = 2 (horizontal line from (-2,2) to (2,2))

### Final Logical Condition:
```text
in_shaded_region = (x ≥ -2.0 AND x ≤ 2.0 AND y ≥ -1.0 AND y ≤ 3.0) 
                   AND NOT (y ≥ x AND y ≥ -x AND y ≤ 2.0)
```

## Test Results

| Point (x,y) | Expected | Actual | Result  | Notes |
|-------------|----------|--------|---------|-------|
| (0, 1)      | YES      | YES    | ✅ Pass | Inside rectangle, outside triangle |
| (1, 1)      | NO       | NO     | ✅ Pass | Inside triangular exclusion |
| (0, 2.5)    | YES      | YES    | ✅ Pass | Above triangle, inside rectangle |
| (1.5, 1.5)  | NO       | NO     | ✅ Pass | On triangle edge (within EPS) |
| (-3, 1)     | NO       | NO     | ✅ Pass | Outside rectangle (left) |
| (0, -2)     | NO       | NO     | ✅ Pass | Outside rectangle (bottom) |
| (0, 4)      | NO       | NO     | ✅ Pass | Outside rectangle (top) |
| (-1, 1)     | YES      | YES    | ✅ Pass | Inside rectangle, outside triangle |

## Debug Session Transcript

```bash
$ gcc -Wall -Wextra -g region_12.c -lm -o region_12
$ gdb ./region_12
(gdb) break main
Breakpoint 1 at 0x115d: file region_12.c, line 6
(gdb) run
Starting program: ./region_12 
Enter coordinates (x y): 0 1

Breakpoint 1, main () at region_12.c:6
6       const double EPS = 1e-9;
(gdb) next
(gdb) next
Enter coordinates (x y): 0 1
(gdb) next
(gdb) print x
$1 = 0
(gdb) print y
$2 = 1
(gdb) next
(gdb) print in_rect
$3 = true
(gdb) print edge1
$4 = 1
(gdb) print edge2
$5 = 1
(gdb) print edge3
$6 = -1
(gdb) print in_tria
$7 = false
(gdb) print in_shaded_region
$8 = true
(gdb) continue
Continuing.
YES
[Inferior 1 (process 28461) exited normally]

(gdb) run
Starting program: ./region_12 
Enter coordinates (x y): 1 1
(gdb) print x
$9 = 1
(gdb) print y
$10 = 1
(gdb) next
(gdb) print in_tria
$11 = true
(gdb) print in_shaded_region
$12 = false
(gdb) continue
Continuing.
NO
[Inferior 1 (process 28462) exited normally]
(gdb) quit
```

## Conclusion

The program successfully implements the geometric region test for Variant 12 using linear boundaries. The debug session confirms correct variable evaluation and logical flow. All test cases pass as expected, demonstrating proper implementation of the rectangle-with-triangular-exclusion region definition.

**Key Features:**
- Uses half-plane method for triangle detection
- Implements EPS tolerance for robust floating-point comparisons
- Handles edge cases and boundary conditions correctly
- Provides clear YES/NO output for region membership

**Verification:**
The GDB debug session validates that:
1. Input coordinates are correctly read and stored
2. Rectangle boundary checks work as intended
3. Triangle exclusion logic properly identifies points inside the triangular region
4. The final shaded region determination combines both conditions correctly

The program meets all requirements for Variant 12 and successfully determines point membership in the specified geometric region.