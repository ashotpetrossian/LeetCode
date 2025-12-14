# 739. Daily Temperatures

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the `i`th day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead. [1]

### Example 1:

**Input:**
```
temperatures = [73,74,75,71,69,72,76,73]
```
**Output:**
```
[1,1,4,2,1,1,0,0]
```

### Example 2:

**Input:**
```
temperatures = [30,40,50,60]
```
**Output:**
```
[1,1,1,0]
```

### Example 3:

**Input:**
```
temperatures = [30,60,90]
```
**Output:**
```
[1,1,0]
```

### Constraints:

- `1 <= temperatures.length <= 10^5` [1]
- `30 <= temperatures[i] <= 100` [1]

## Intuition

The problem asks us to find the number of days until a future day with a warmer temperature. For each day, we need to look to its right in the array and find the first temperature that is strictly greater. This is a classic "Next Greater Element" problem.

A brute-force approach of using nested loops to check every subsequent day for each day would result in an O(n^2) time complexity, which would be too slow given the constraint of `10^5` elements.

A more efficient approach is to use a monotonic stack. We can process the temperatures from left to right and use a stack to keep track of the indices of days for which we haven't yet found a warmer day. By maintaining the stack in a monotonically decreasing order of temperatures, we can efficiently find the next warmer day for each day.

## Approach

1.  Initialize a result array `res` of the same size as `temperatures`, filled with zeros. This handles the case where no warmer future day exists.
2.  Initialize an empty stack `st` that will store indices of the `temperatures` array.
3.  Iterate through the `temperatures` array using both the index `i` and the temperature `temp`.
4.  For each temperature, check the stack: While the stack is not empty and the current temperature `temp` is greater than the temperature at the index on top of the stack (`temperatures[st[-1]]`), we have found the next warmer day for the day at index `st[-1]`.
    a.  Calculate the waiting days: `i - st[-1]`.
    b.  Update the result for that index: `res[st[-1]] = i - st[-1]`.
    c.  Pop the index from the stack, as we have now processed it.
5.  After the `while` loop, push the current index `i` onto the stack. This index represents a day that is waiting for a future warmer day.
6.  After iterating through all the temperatures, the `res` array will contain the required number of waiting days for each day. Return `res`.

## Time and Space Complexity

### Time Complexity: O(n)

Each index is pushed onto and popped from the stack at most once. This means that despite the nested `while` loop, every element is processed a constant number of times. Therefore, the total time complexity is linear with respect to the number of elements in the input array.

### Space Complexity: O(n)

In the worst-case scenario, such as a strictly decreasing array of temperatures (e.g., `[90, 80, 70, 60]`), all indices will be pushed onto the stack. This means the space required by the stack can be proportional to the number of elements in the input array.