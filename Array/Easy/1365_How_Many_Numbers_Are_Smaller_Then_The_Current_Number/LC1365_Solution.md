## 1365. How Many Numbers Are Smaller Than the Current Number

Given the array `nums`, for each `nums[i]` find out how many numbers in the array are smaller than it. That is, for each `nums[i]` you have to count the number of valid `j`'s such that `j != i` and `nums[j] < nums[i]`.

Return the answer in an array.

**Example 1:**

```
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number.
For nums[2]=2 there exist one smaller number (1). 
For nums[3]=2 there exist one smaller number (1). 
For nums[4]=3 there exist three smaller numbers (1, 2 and 2).
```

**Example 2:**

```
Input: nums = [6,5,4,8]
Output: [2,1,0,3]
```

**Constraints:**

*   `2 <= nums.length <= 500`
*   `0 <= nums[i] <= 100`

### Intuition

A brute-force approach would be to compare every element with every other element, which would be slow (O(n^2)). A more efficient way is to figure out the counts of all numbers first. The problem constraints are a big hint: the numbers in the array are limited to the range `0` to `100`. This small, fixed range makes a frequency counting approach (similar to counting sort) very effective.

The idea is to first count how many times each number appears. Then, we can use this frequency data to determine, for any given number `x`, how many numbers in the array are smaller than `x`.

### Approach

The algorithm uses a frequency array and prefix sums to solve the problem in linear time.

1.  **Frequency Count**: Create a frequency array, let's call it `counts`, of size 101 (to cover numbers 0-100). Iterate through the input `nums` and populate this array. After this pass, `counts[x]` will hold the number of times `x` appears in `nums`.
2.  **Calculate Prefix Sums**: Transform the `counts` array into a running sum. Iterate from 1 to 100, and for each index `i`, update `counts[i] = counts[i] + counts[i-1]`. After this step, `counts[x]` will represent the total count of numbers in the input that are less than or equal to `x`.
3.  **Build the Result**: Create a new result array. Iterate through the original `nums` array one last time. For each `num`:
    *   If `num` is 0, no numbers are smaller than it, so the answer is 0.
    *   If `num` is greater than 0, the number of elements strictly smaller than `num` is given by `counts[num - 1]`.
    *   Append this value to your result array.
4.  **Return Result**: Return the newly created result array.

### Time and Space Complexity

*   **Time Complexity: O(n + k)**
    Where `n` is the length of `nums` and `k` is the range of possible number values (101 in this case). We have three separate loops: one of size `n`, one of size `k`, and another of size `n`. This simplifies to O(n + k). Since `k` is a constant (101), the complexity is effectively linear, **O(n)**.

*   **Space Complexity: O(k)**
    We use an auxiliary array `counts` of size `k` (101). Since this size is constant and does not depend on the input size `n`, the space complexity is **O(1)** (constant space). The space for the output array is not typically counted.