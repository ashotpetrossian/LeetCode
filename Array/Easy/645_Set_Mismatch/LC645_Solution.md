## 645. Set Mismatch

You have a set of integers `s`, which originally contains all the numbers from 1 to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in the repetition of one number and the loss of another number.

You are given an integer array `nums` representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**

```
Input: nums = [1,2,2,4]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1]
Output: [1,2]
```

**Constraints:**

*   `2 <= nums.length <= 10^4`
*   `1 <= nums[i] <= 10^4`

### Intuition

The problem guarantees that the input array contains numbers that should have been a complete sequence from `1` to `n`, but with one number duplicated and one missing. The numbers in the array are all positive and within the range of the array's length. This structure is a strong hint that we can use the array's indices to track the numbers we've seen.

The core idea is to use the array itself as a hash map. We can map each number `k` to the index `k-1`. By changing the sign of the number at that index, we can "mark" `k` as seen. If we encounter a number and its corresponding index is already marked (i.e., negative), we've found our duplicate.

### Approach

The strategy is to iterate through the array, using the values to mark corresponding indices.

1.  **Initialize Variables**: We'll need `duplicate` and `missing` variables to store our results.
2.  **First Pass (Marking and Finding Duplicate)**: Iterate through each `num` in the `nums` array.
    *   Calculate the index that corresponds to the current number: `index = abs(num) - 1`. We use the absolute value because the sign at that position might have been flipped by a previous step.
    *   Check the value at `nums[index]`. If it's already negative, it means we have seen this number before. Therefore, `abs(num)` is the duplicate number.
    *   If `nums[index]` is positive, we mark it as seen by negating it: `nums[index] *= -1`.
3.  **Second Pass (Finding Missing Number)**: After the first pass, exactly one index will still contain a positive number. This is because the number corresponding to that index was never seen in the input array (it's the missing one).
    *   Iterate through the array from `i = 0` to `n-1`.
    *   The first index `i` where `nums[i]` is still positive tells us the missing number is `i + 1`.
4.  **Return Result**: Return the `duplicate` and `missing` numbers in an array.

### Time and Space Complexity

*   **Time Complexity: O(n)**
    We perform two separate, non-nested passes through the array, each of length `n`. This results in a time complexity of O(n) + O(n), which simplifies to O(n).

*   **Space Complexity: O(1)**
    The algorithm modifies the input array in-place and uses only a few extra variables to store the `duplicate` and `missing` values. The space required does not scale with the input size `n`, so the space complexity is constant.