# 636. Exclusive Time of Functions

## Description

On a single-threaded CPU, we execute a program containing `n` functions. Each function has a unique ID between `0` and `n-1`.

Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed.

You are given a list of logs, where `logs[i]` represents the `i`th log message formatted as a string `"{function_id}:{_start_ | _end_}:{timestamp}"`. For example, `"0:start:3"` means that function `0` started at the beginning of timestamp `3`, and `"1:end:2"` means that function `1` ended at the end of timestamp `2`.

A function's **exclusive time** is the sum of execution times for all function calls in the program. For example, if a function is called twice, its exclusive time is the sum of the execution times for both calls.

Return the exclusive time of each function in an array, where the value at the `i`th index represents the total exclusive time for the function with ID `i`.

---

### Examples

**Example 1:**

'''

**Input:** `n = 2`, `logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]`

**Output:** `[3, 4]`

**Explanation:**
Function 0 starts at the beginning of time 0, then it executes 2 for two units of time.
Then, function 1 starts at the beginning of time 2, executes for four units of time, and ends at the end of time 5.
Function 0 resumes execution at the beginning of time 6 and executes for one unit of time.
So, function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.
'''

**Example 2:**

'''
**Input:** `n = 1`, `logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]`

**Output:** `[8]`

**Explanation:**
Function 0 starts at time 0, executes for 2 units of time, and recursively calls itself.
Function 0 (recursive call) starts at time 2, executes for 4 units of time, and ends at time 5.
Function 0 (initial call) resumes execution then immediately calls itself again.
Function 0 (2nd recursive call) starts at time 6, executes for 1 unit of time, and ends at time 6.
Function 0 (initial call) resumes execution at time 7, executes for 1 unit of time, and ends at time 7.
'''

**Example 3:**

'''
**Input:** `n = 1`, `logs = ["0:start:0","0:end:0"]`

**Output:** `[1]`
'''

---

### Constraints

*   `1 <= n <= 100`
*   `1 <= logs.length <= 500`
*   `0 <= function_id < n`
*   `0 <= timestamp <= 10^9`
*   No two start events or two end events will happen at the same timestamp.
*   For each function, every start log will be followed by an end log.

---

## 1. Intuition

The problem describes a sequence of function calls and returns, which naturally follows a Last-In, First-Out (LIFO) order. When a function starts, it becomes the currently executing function. If it calls another function, the new function preempts it and starts executing. When the new function ends, the previous one resumes. This nested execution structure is a perfect use case for a stack.

We can use a stack to keep track of the chain of active function calls. The function at the top of the stack is the one currently running on the CPU. By processing the logs chronologically, we can calculate the time spent in each function.

## 2. Approach

We can iterate through the logs and use a stack to manage the active function calls. The stack will store the `function_id` of the functions in the current call stack.

1.  Initialize an array, `result`, of size `n` with all zeros. This will store the exclusive execution time for each function.
2.  Initialize an empty stack to keep track of the `function_id` of the currently running functions.
3.  Initialize a variable, `prev_time`, to 0. This will mark the timestamp of the previous event.
4.  Iterate through each log entry:
    a. Parse the log string to get the `function_id`, event `type` (`start` or `end`), and `timestamp`.
    b. If the stack is not empty, it means a function was running just before this current log event. The time elapsed since the last event is `timestamp - prev_time`. This duration belongs to the function that was at the top of the stack. Add this duration to its exclusive time in the `result` array.
    c. Update `prev_time` to the current `timestamp`.
    d. If the event `type` is `start`:
        i. Push the `function_id` onto the stack.
    e. If the event `type` is `end`:
        i. A function has just finished. The duration of this last time unit (`timestamp - prev_time + 1`) belongs to this function. We already added `timestamp - prev_time` in step 4b, so we just need to add `1` to its exclusive time in the `result` array.
        ii. Pop the `function_id` from the stack, as it is no longer executing.
        iii. Increment `prev_time` by 1. This is because an `end` log at time `t` means the function runs for the entire time unit `t`. The next event, or the resumption of the parent function, will effectively start at `t + 1`.
5.  After iterating through all the logs, the `result` array will contain the total exclusive time for each function.

This approach correctly handles the time allocation. When a function is running, its timer is ticking. When it's preempted by another function call, its timer pauses. When the inner function returns, the outer function's timer resumes.

## 3. Time and Space Complexity

*   **Time Complexity:** `O(L)`
    *   We iterate through the list of logs once. `L` is the number of logs.
    *   Parsing each log string takes a constant amount of time as the format is fixed.
    *   Stack operations (push and pop) are `O(1)`.

*   **Space Complexity:** `O(n)`
    *   The `result` array requires `O(n)` space, where `n` is the number of functions.
    *   The space used by the stack can go up to `O(n)` in the worst case of deeply nested function calls (e.g., a chain of `n` functions calling each other).

Therefore, the overall space complexity is dominated by the size of the result array and the stack, resulting in `O(n)`.