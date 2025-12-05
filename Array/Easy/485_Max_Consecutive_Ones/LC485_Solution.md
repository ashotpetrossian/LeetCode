## 485. Max Consecutive Ones

Given a binary array `nums`, return the maximum number of consecutive 1's in the array.

**Example 1:**

```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
```

**Example 2:**

```
Input: nums = [1,0,1,1,0,1]
Output: 2
```

**Constraints:**

*   `1 <= nums.length <= 10^5`
*   `nums[i]` is either `0` or `1`.

### Intuition

The goal is to find the longest "run" or "streak" of `1`s in a row. We can solve this by simply walking through the array and keeping track of two things: the length of the current streak of `1`s and the longest streak we have seen so far.

### Approach

The strategy is to iterate through the array once, maintaining a count of the current consecutive ones.

1.  **Initialize Counters**: Create two integer variables, `current_count` to track the active streak of ones, and `max_count` to store the highest streak found. Both start at `0`.
2.  **Iterate Through the Array**: Loop through each number in the `nums` array.
    *   If the number is `1`, increment `current_count`.
    *   If the number is `0`, the streak is broken. We must now check if the streak that just ended is the longest one we've seen. Update `max_count = max(max_count, current_count)`, and then reset `current_count` to `0`.
3.  **Final Check**: After the loop finishes, the last sequence might be a streak of ones (e.g., `[1,0,1,1]`). This final streak was never interrupted by a `0`, so our check inside the loop wouldn't have updated `max_count` for it. We perform one last check: `return max(max_count, current_count)`.

This approach ensures we find the maximum streak in a single pass.

### Time and Space Complexity

*   **Time Complexity: O(n)**
    We perform a single pass through the array of length `n`. All operations inside the loop are constant time. Thus, the time complexity is linear with respect to the size of the input array.

*   **Space Complexity: O(1)**
    The algorithm uses only a fixed number of variables (`max_count`, `current_count`) to store the counts. The amount of extra memory used does not grow with the size of the input array, making the space complexity constant.
