1929: Concatenation of Array

Given an integer array `nums` of length `n`, you want to create an array `ans` of length `2n` where `ans[i] == nums[i]` and `ans[i + n] == nums[i]` for `0 <= i < n` (0-indexed).

Specifically, `ans` is the concatenation of two `nums` arrays.

Return the array `ans`.

 

**Example 1:**

```
Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
```

**Example 2:**

```
Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
```

 

**Constraints:**

*   `n == nums.length`
*   `1 <= n <= 1000`
*   `1 <= nums[i] <= 1000`

### Intuition

The core idea is to construct a new array by appending the original input array to itself. The resulting array will be twice the length of the original. The first half of the new array will be a copy of the original array, and the second half will also be a copy of the original array.

### Approach

1.  **Allocate Memory**: Create a new array with a size twice that of the input array.
2.  **Populate the Array**: Iterate through the original array from the first to the last element. In each step of the iteration, place the current element at two positions in the new array:
    *   At its original index.
    *   At its original index plus the length of the input array.
3.  **Return Result**: After the iteration is complete, the newly created array will contain two consecutive copies of the original and can be returned.

### A Note on "In-Place" Solutions

A common point of discussion is whether this problem can be solved "in-place." In algorithmic analysis, an in-place operation modifies the input data structure directly, typically using only a constant amount of extra space (O(1)).

For this problem, a true in-place solution is not feasible. The problem requires us to return an array of length `2n` from an input of length `n`. The original array simply does not have enough capacity to hold the doubled output. Any solution must, therefore, allocate a new array with a size of at least `2n`.

Even in languages where arrays can be dynamically resized, this operation typically involves creating a new, larger array behind the scenes and copying the old elements over. This means that while it might look like a single-line, in-place modification in the code, the underlying process still requires O(n) space for the new array.

### Time and Space Complexities

*   **Time Complexity: O(n)**
    We iterate through the input array `nums` of length `n` a single time. Inside the loop, we perform two assignment operations, which take constant time, O(1). Therefore, the total time complexity is proportional to `n`, resulting in O(n).

*   **Space Complexity: O(n)**
    We are required to create a new array `ans` of length `2n` to store the result. The space needed is directly proportional to the size of the input `n`. Therefore, the space complexity is O(2n), which simplifies to O(n). This does not include the space taken by the output array, as is common in complexity analysis, but if the space for the output is counted, it's O(n).