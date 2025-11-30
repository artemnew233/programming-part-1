**Course:** Programming, Part 1 \
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Artem Smeliantsev \
**Date:** 30.11.2025  

---

## Task Description

The goal of this combined lab work was to implement **Variant 12** for two separate assignments:
1.  **Lab 08.1 (Matrix):** Implement four specific tasks related to 2D array manipulation.
2.  **Lab 08.2 (Arrays):** Implement five specific tasks related to 1D array manipulation.

The solutions were implemented in simple C code without complex external libraries, focusing on core programming logic.

## Lab 08.1: 2D Arrays (Matrix) Implementation

### Tasks Implemented (Variant 12)

| Group | Task No. | Task Description |
| :--- | :--- | :--- |
| **Group 1** | 6 | Find the maximum in the upper triangle (above main diagonal). |
| **Group 2** | 1 | Reverse each row of the matrix. |
| **Group 3** | 7 | Calculate the sum of all positive elements. |
| **Group 4** | 4 | Find the second smallest element in the 1D array (after flattening). |

### Runtime Output (Example)

The program was run with a sample 4x4 matrix.

```text
--- Original Matrix ---
Matrix (4x4):
   1   5  -3   8
   9   2   7  -4
   6  10   3   0
  -1  12   4  11

1. Max in Upper Triangle (i < j): 8
2. Matrix after reversing each row:
   8  -3   5   1
  -4   7   2   9
   0   3  10   6
  11   4  12  -1

3. Sum of Positive Elements: 78
4. Second Smallest Unique Element: -3
```

## Lab 08.2: One-Dimensional Arrays Implementation

### Tasks Implemented (Variant 12)

| Group | Task No. | Task Description |
| :--- | :--- | :--- |
| **Group 1** | 12 | Calculate the average value. |
| **Group 2** | 12 | Find the largest element. |
| **Group 3** | 12 | Replace negative values with zeros. |
| **Group 4** | 12 | Selection Sort. |
| **Group 5** | 12 | Count of unique elements. |

### Runtime Output (Example)

The program was run with a sample array: `{5, -2, 10, 5, 8, -2, 1, 10, 3, 1}`.

```text
Matrix (4x4):
   1   5  -3   8
   9   2   7  -4
   6  10   3   0
  -1  12   4  11

1. Max in Upper Triangle (i < j): 8

2. Matrix after reversing each row:
Matrix (4x4):
   8  -3   5   1
  -4   7   2   9
   0   3  10   6
  11   4  12  -1

3. Sum of Positive Elements: 78

4. Second Smallest Unique Element: -3
```

---

### Observations and Conclusion

Both lab assignments for Variant 12 were successfully implemented using simple C code.

*   **Lab 08.1 (Matrix):** The implementation successfully handled 2D array indexing for the upper triangle, in-place row reversal, and combined 1D/2D array logic for finding the second smallest element.
*   **Lab 08.2 (Arrays):** The implementation covered fundamental 1D array operations, including calculation, searching, modification, sorting (Selection Sort), and counting unique elements.

