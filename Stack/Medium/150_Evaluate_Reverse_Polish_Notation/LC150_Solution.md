You are given an array of strings `tokens` that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an *integer* that represents the value of the expression.

**Note** that:

*   The valid operators are `+`, `-`, `*`, and `/`.
*   Each operand may be an integer or another expression.
*   The division between two integers always **truncates toward zero**.
*   There will not be any division by zero.
*   The input represents a valid arithmetic expression in a reverse polish notation.
*   The answer and all intermediate calculations can be represented in a **32-bit** integer.

**Example 1:**

**Input:** tokens = ["2","1","+","3","*"]
**Output:** 9
**Explanation:** ((2 + 1) * 3) = 9

**Example 2:**

**Input:** tokens = ["4","13","5","/","+"]
**Output:** 6
**Explanation:** (4 + (13 / 5)) = 6

**Example 3:**

**Input:** tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
**Output:** 22
**Explanation:** ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

**Constraints:**

*   `1 <= tokens.length <= 104`
*   `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

### 1. Intuition

The problem of evaluating a Reverse Polish Notation (RPN) expression is a classic use case for a stack. The LIFO (Last-In, First-Out) nature of a stack allows us to store operands until an operator is encountered. When an operator appears, we apply it to the most recently seen operands, which are conveniently at the top of the stack.

### 2. Approach

1.  Initialize an empty stack to store integer operands.
2.  Create a dictionary that maps operator strings (`"+", "-", "*", "/"` ) to their corresponding lambda functions for quick lookup.
3.  Iterate through each token in the input list.
4.  If the token is a number, convert it to an integer and push it onto the stack.
5.  If the token is an operator, pop the top two elements from the stack. The first element popped is the right-hand operand, and the second is the left-hand operand.
6.  Perform the operation using the function retrieved from the dictionary and push the result back onto the stack.
7.  After iterating through all tokens, the stack will contain a single element, which is the final result of the expression. Return this value.

### 3. Time and Space Complexities

*   **Time Complexity: O(n)**
    Each token is processed exactly once. Pushing to and popping from the stack are O(1) operations. Therefore, the time complexity is linear with respect to the number of tokens, `n`.

*   **Space Complexity: O(n)**
    In the worst-case scenario, the stack will hold all the numbers before any operators are processed. The maximum number of operands on the stack is roughly `n/2`. Thus, the space required is proportional to the number of tokens.