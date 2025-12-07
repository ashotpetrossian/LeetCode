# 448. Find All Numbers Disappeared in an Array

## Problem Description

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return an array of all the integers in the range `[1, n]` that do not appear in `nums`.

### Example 1:

**Input:** `nums = [4,3,2,7,8,2,3,1]`  
**Output:** `[5,6]`

### Example 2:

**Input:** `nums = [1,1]`  
**Output:** `[2]`

### Constraints:

*   `n == nums.length`
*   `1 <= n <= 10^5`
*   `1 <= nums[i] <= n`

**Follow up:** Could you do it without extra space and in `O(n)` runtime? You may assume the returned list does not count as extra space.

---

## Solution Analysis

The provided solution uses an in-place sorting technique often called **Cyclic Sort**. It's a highly efficient method for problems where the input array contains numbers in a specific range (like 1 to n).

### Intuition

The core idea is to treat the array itself as a map to store information. If the array were complete and sorted, the number `1` would be at index `0`, `2` at index `1`, and so on. In general, a number `k` should be at index `k - 1`.

By placing each number in its "correct" position, we can later iterate through the array and identify which positions do not hold the correct number. If index `i` does not contain the number `i + 1`, it means `i + 1` was missing from the original input.

### Approach

The algorithm consists of two main phases:

1.  **Placement Phase (Cyclic Sort):**
    *   Iterate through the array from the beginning.
    *   For the element at the current index `i`, determine its correct position, which is `correct_index = value - 1`.
    *   Check if the element is already at its correct position. A simple way to check is to see if the value at the current index is the same as the value at its `correct_index`.
    *   If the element is **not** in its correct place, swap it with the element at its `correct_index`. We do not advance our main iterator `i` yet, because the new element that was swapped into the current position also needs to be placed correctly.
    *   If the element **is** already in its correct place (or is a duplicate of a number that is already correctly placed), we can move on to the next index by incrementing `i`.
    *   This process continues until the entire array has been traversed. After this phase, every number in the array is in its correct index, except for the indices that correspond to missing numbers.

2.  **Identification Phase:**
    *   Iterate through the modified array from index `0` to `n - 1`.
    *   For each index `i`, check if the value at that index is equal to `i + 1`.
    *   If `value != i + 1`, it signifies that the number `i + 1` was never present in the original array, so we add `i + 1` to our list of missing numbers.
    *   Return the list of missing numbers.

### Complexity Analysis

*   **Time Complexity: O(n)**
    *   The placement phase involves a `while` loop. Although it seems like there could be many swaps for each position, each number is swapped at most once to reach its final, correct destination. Therefore, the total number of swaps is at most `n`. The traversal is O(n), making the total time for this phase O(n).
    *   The identification phase is a single loop through the array, which takes O(n) time.
    *   The total time complexity is O(n) + O(n) = **O(n)**.

*   **Space Complexity: O(1)**
    *   The algorithm modifies the array in-place.
    *   The space required for the output list is not counted towards the auxiliary space complexity, as per the problem's follow-up constraint.
    *   Therefore, the space complexity is **O(1)**.