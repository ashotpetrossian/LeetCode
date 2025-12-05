## 1470. Shuffle the Array

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

**Example 1:**

```
Input: nums =, n = 3
Output: 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is.
```

**Example 2:**

```
Input: nums =, n = 4
Output:
```

**Example 3:**

```
Input: nums =, n = 2
Output:
```

**Constraints:**

*   `1 <= n <= 500`
*   `nums.length == 2n`
*   `1 <= nums[i] <= 10^3`

### Intuition

The problem asks us to re-arrange an array by interleaving its two halves. The input array has all the `x` elements first, followed by all the `y` elements. The goal is to create a new array by picking one `x` and one `y` element at a time.

### Approach

The most direct way to solve this is to build a new result array.

1.  **Create a result array**: Initialize a new array with a size of `2n` to hold the shuffled elements.
2.  **Iterate and Place**: Loop `n` times, from `i = 0` to `n-1`. In each step:
    *   Take the `i`-th element from the first half (`nums[i]`) and place it in the result array.
    *   Take the `i`-th element from the second half (`nums[i + n]`) and place it right after the first one.
3.  **Return**: Once the loop is finished, the result array will be correctly shuffled, and we can return it.

This approach matches the provided C++ and Python solutions, which efficiently pre-allocate the result array and fill it in a single pass.

### A Note on "In-Place" Solutions

An in-place solution with O(1) extra space is complex and often not expected for this problem level. It would involve encoding two numbers into a single array slot and then decoding them later, which can be tricky and less readable. Since the problem asks to *return* a new array, creating one is the most natural and efficient approach.

### Time and Space Complexity

*   **Time Complexity: O(n)**
    We iterate `n` times. Inside the loop, we perform constant-time assignment operations. Therefore, the total time is directly proportional to `n`.

*   **Space Complexity: O(n)**
    We create a new result array of size `2n`. The space required is proportional to `n`. If we consider the standard convention where the space for the output array is counted, the complexity is O(n).