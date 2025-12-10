# 3667. Sort Array By Absolute Value

## Problem Description

Given an array of integers `nums`, sort the array in-place in non-decreasing order based on the absolute value of each element. If two numbers have the same absolute value, their relative order in the sorted array is not specified.



**Example 1:**

'''
Input: `nums = [-4, -1, 0, 3, 10]`
Output: `[0, -1, 3, -4, 10]`
Explanation: The absolute values are `[4, 1, 0, 3, 10]`. Sorting by these values gives `[0, 1, 3, 4, 10]`, which corresponds to the elements `[0, -1, 3, -4, 10]`.
'''


**Example 2:**


'''
Input:** `nums = [2, -3, -1, 5, -4]`
Output:** `[-1, 2, -3, -4, 5]`
Explanation:** The absolute values are `[2, 3, 1, 5, 4]`. Sorting by these values gives `[1, 2, 3, 4, 5]`, which corresponds to the elements `[-1, 2, -3, -4, 5]`.
'''


**Constraints:**

*(Typical constraints for such a problem)*
*   `1 <= nums.length <= 10^4`
*   `-10^4 <= nums[i] <= 10^4`

---

## Solution

The goal is to sort an array based on a custom criterion: the absolute value of its elements. Most programming languages provide a built-in sort function that can be customized using a key or a custom comparator.

### Approach

We can use the standard library's sort function and provide it with a custom comparison logic.

1.  **C++**: We use `std::sort` from the `<algorithm>` header. This function can take a third argument, a lambda function ` { ... }`, which acts as a custom comparator. This lambda tells the sort algorithm to order elements `a` and `b` based on whether the absolute value of `a` is less than the absolute value of `b`. The sort is performed in-place.

2.  **Python**: Python's built-in `sorted()` function (or the `list.sort()` method) is the ideal tool. It accepts a `key` argument. By passing `key=abs`, we instruct the function to use the absolute value of each element as the basis for comparison during the sort. The `sorted()` function returns a new sorted list, while `list.sort()` would modify the list in-place.

This approach is efficient and leverages the highly optimized sorting algorithms provided by the standard libraries of both languages.

### Complexity

*   **Time Complexity:** `O(N log N)`, where `N` is the number of elements in the array. This is the standard time complexity for comparison-based sorting algorithms like Timsort (used in Python) or Introsort (a common implementation for `std::sort`).

*   **Space Complexity:**
    *   **C++ (`std::sort`)**: `O(log N)` to `O(N)` depending on the implementation of the standard library's sort (Introsort typically requires `O(log N)` stack space). The sorting is done in-place, so it doesn't use extra space proportional to the input size for the output.
    *   **Python (`sorted`)**: `O(N)` because `sorted()` creates a new list to store the result. If sorting in-place with `nums.sort(key=abs)`, the space complexity would be `O(log N)` or `O(N)` depending on the implementation details of Timsort.
