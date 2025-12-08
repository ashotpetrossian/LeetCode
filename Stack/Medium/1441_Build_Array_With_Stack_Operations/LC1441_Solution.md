# 1441. Build an Array With Stack Operations

## Description

You are given an integer array `target` and an integer `n`.

You have an initially empty stack and a stream of numbers `1, 2, 3, ..., n`.

In one operation, you can:

*   `"Push"` the next number from the stream onto the top of the stack.
*   `"Pop"` the number on the top of the stack.

You are given a `target` array. Return *the stack operations needed to build* `target`. The `target` array is **strictly increasing** and contains numbers between `1` and `n`.

The test cases are generated so that the answer is unique.

---

### Examples

**Example 1:**
>**Input:** target = [1,3], n = 3
>**Output:** ["Push","Push","Pop","Push"]
>**Explanation:**
Read 1 and push it -> [1]
Read 2 and push it -> [1,2]
Pop the top of the stack -> [1]
Read 3 and push it -> [1,3]

**Example 2:**
>**Input:** target = [1,2,3], n = 3
>**Output:** ["Push","Push","Push"]

**Example 3:**
>**Input:** target = [1,2], n = 4
>**Output:** ["Push","Push"]
>**Explanation:** You only need to read the first 2 numbers and stop.

---

### Constraints

*   `1 <= target.length <= 100`
*   `1 <= n <= 100`
*   `1 <= target[i] <= n`
*   `target` is strictly increasing.

---

## 1. Intuition

The core idea is to simulate the process described in the problem. We have a stream of numbers from `1` to `n`. We can iterate through this stream, and for each number, we must first "Push" it onto our conceptual stack. After pushing, we decide if this number should be kept or discarded. We compare the number we just pushed with the current element we need for our `target` array. If it's the correct number, we keep it and move on to the next number in the `target`. If it's not the correct number, we must "Pop" it to discard it and continue the process.

## 2. Approach

The implementation directly follows the simulation intuition:

1.  Initialize an empty list, `res`, to store the sequence of operations ("Push", "Pop").
2.  Initialize an index `j = 0` to keep track of our current position in the `target` array.
3.  Iterate with a number `i` from `1` up to `n`. This loop represents reading from the stream of numbers.
4.  For each number `i`, we must first read it from the stream, which corresponds to a `"Push"` operation. So, append `"Push"` to `res`.
5.  Next, check if the number `i` is the one we currently need. The number we need is `target[j]`.
6.  If `i` is **not** equal to `target[j]`, it means we've pushed a number that isn't part of the final target. We must immediately discard it by appending a `"Pop"` operation to `res`.
7.  If `i` **is** equal to `target[j]`, it means we have successfully placed the correct number on our stack. We then advance our target index by incrementing `j`.
8.  As an optimization, we check if `j` has reached the end of the `target` array. If it has, we have successfully built the target, and there's no need to process further numbers from the stream. We can `break` the loop.
9.  Finally, return the `res` list containing all the operations.

## 3. Time and Space Complexities

*   **Time Complexity: O(n)**
    The algorithm iterates from `1` up to at most `n`. In the worst-case scenario (e.g., `target = [n]`), the loop will run `n` times. Since all operations inside the loop (list append, comparison) are O(1), the total time complexity is determined by the number of iterations, making it O(n).

*   **Space Complexity: O(n)**
    The space complexity is determined by the size of the output list, `res`. In the worst-case scenario (e.g., `target = [n]`), we perform a "Push" and a "Pop" for numbers `1` through `n-1`, and one final "Push" for `n`. This results in `2 * (n-1) + 1 = 2n - 1` operations. Therefore, the space required to store the result is proportional to `n`, making the space complexity O(n).

