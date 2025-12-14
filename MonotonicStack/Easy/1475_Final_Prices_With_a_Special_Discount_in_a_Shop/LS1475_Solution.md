# 1475. Final Prices With a Special Discount in a Shop

You are given an integer array `prices` where `prices[i]` is the price of the `i`th item in a shop. [1]

There is a special discount for items in the shop. If you buy the `i`th item, then you will receive a discount equivalent to `prices[j]` where `j` is the minimum index such that `j > i` and `prices[j] <= prices[i]`. Otherwise, you will not receive any discount at all. [1]

Return an integer array `answer` where `answer[i]` is the final price you will pay for the `i`th item of the shop, considering the special discount. [1]

### Example 1:

**Input:**
```
prices = [8,4,6,2,3]
```
**Output:**
```
[4,2,4,2,3]
```
**Explanation:**
- For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4. [1]
- For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2. [1]
- For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4. [1]
- For items 3 and 4 you will not receive any discount at all. [1]

### Example 2:

**Input:**
```
prices = [1,2,3,4,5]
```
**Output:**
```
[1,2,3,4,5]
```
**Explanation:** In this case, for all items, you will not receive any discount at all.

### Example 3:

**Input:**
```
prices = [10,1,1,6]
```
**Output:**
```
[9,0,1,6]
```

### Constraints:

- `1 <= prices.length <= 500` [2]
- `1 <= prices[i] <= 1000` [2]

## Intuition

The problem asks us to find the next smaller or equal element to the right for each price in the array. If such an element exists, we apply a discount. If not, the price remains the same. A brute-force approach would involve nested loops, resulting in an O(n^2) time complexity.

A more efficient method is to use a monotonic stack. A monotonic stack maintains its elements in either an increasing or decreasing order. For this problem, we can use a monotonically increasing stack to keep track of the indices of prices for which we haven't yet found a discount (a smaller or equal price to their right).

As we iterate through the prices, if the current price is smaller than or equal to the price at the index on top of the stack, it means we've found the discount for the item corresponding to the index at the top of the stack. We can then apply the discount and pop from the stack. We repeat this process until the stack is empty or the price at the top of the stack is less than the current price.

## Approach

1.  Initialize a result array `res` as a copy of the input `prices` array. This handles cases where no discount is applied.
2.  Initialize an empty stack `st` which will store indices of the `prices` array.
3.  Iterate through the `prices` array with their indices (`i`) and values (`price`).
4.  For each price, check the stack. While the stack is not empty and the current `price` is less than or equal to the price at the index stored at the top of the stack (`prices[st[-1]]`):
    a.  This current price is the discount for the item at index `st[-1]`.
    b.  Update the result: `res[st[-1]] -= price`.
    c.  Pop the index from the stack as we have now found its discount.
5.  After the while loop, push the current index `i` onto the stack. This index represents a price waiting for a future smaller or equal price to act as its discount.
6.  After iterating through all the prices, the `res` array will contain the final prices. Any indices remaining in the stack correspond to items that did not get a discount, but we have already handled this by initializing `res` with the original prices.
7.  Return the `res` array.

This approach is known as finding the "Next Smaller Element" and is a classic application of a monotonic stack. [5]

## Time and Space Complexity

### Time Complexity: O(n)

Although there is a nested `while` loop inside the `for` loop, each index is pushed onto and popped from the stack at most once. Therefore, the total number of operations is proportional to the number of elements in the `prices` array, giving us a linear time complexity.

### Space Complexity: O(n)

In the worst-case scenario (e.g., a strictly increasing array of prices like `[1,2,3,4,5]`), all indices will be pushed onto the stack. Therefore, the space required by the stack is proportional to the number of elements in the input array.