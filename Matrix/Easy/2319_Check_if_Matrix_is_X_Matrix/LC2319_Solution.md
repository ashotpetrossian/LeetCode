# 2319. Check if Matrix Is X-Matrix

A square matrix is said to be an **X-Matrix** if both of the following conditions hold:

1. All the elements in the diagonals of the matrix are **non-zero**.
2. All other elements are 0.

Given a 2D integer array `grid` of size `n x n` representing a square matrix, return `true` if `grid` is an X-Matrix, otherwise, return `false`.

### Example 1:

```
Input: grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
Output: true
Explanation: The diagonal elements are non-zero. All other elements are 0. Hence, grid is an X-Matrix.
```

### Example 2:

**Input:** `grid = [[5,7,0],[0,3,1],[0,5,0]]`  
**Output:** `false`  
**Explanation:** The element at `grid[0][1]` is 7, which is not on a diagonal and is non-zero. Hence, `grid` is not an X-Matrix.
```
Input: grid = [,,]
Output: false
Explanation: The element at grid is 7, which is not on a diagonal and is non-zero. Hence, grid is not an X-Matrix.
```

### Constraints:

*   `n == grid.length == grid[i].length`
*   `3 <= n <= 100`
*   `0 <= grid[i][j] <= 10^5`

---

### 1. Intuition

The problem asks us to validate if a given matrix conforms to the two specific rules of an "X-Matrix". The most direct way to confirm this is to check every cell of the matrix against these rules. For any given cell, we first need to determine if it lies on one of the two diagonals. If it does, its value must be non-zero. If it doesn't, its value must be zero. If we find any cell that violates its respective rule, the matrix is not an X-Matrix.

### 2. Approach

We can iterate through each cell of the `n x n` matrix using nested loops, with `i` representing the row index and `j` representing the column index. For each cell `grid[i][j]`, we check its position.

A cell `(i, j)` is on the main diagonal if `i == j`.
A cell `(i, j)` is on the anti-diagonal if `i + j == n - 1`.

So, for each cell `(i, j)`:
1.  If it is a diagonal element (`i == j` or `i + j == n - 1`), we check if `grid[i][j]` is `0`. If it is, we immediately return `false`.
2.  If it is not a diagonal element, we check if `grid[i][j]` is not `0`. If it is non-zero, we immediately return `false`.

If the loops complete without finding any violations, it means the matrix satisfies all conditions, and we can return `true`.

### 3. Complexity

*   **Time Complexity:** `O(n^2)`  
    We must iterate through every element of the `n x n` grid once. Since there are `n * n` elements, the time complexity is quadratic with respect to the size of the matrix dimension `n`.

*   **Space Complexity:** `O(1)`  
    The algorithm uses a fixed amount of extra space for variables like loop counters and the matrix size `n`. This space does not grow with the input size, so the space complexity is constant.