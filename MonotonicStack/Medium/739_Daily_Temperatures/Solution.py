from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0] * n
        st = []

        for i, num in enumerate(temperatures):
            while st and temperatures[st[-1]] < num:
                res[st[-1]] = i - st[-1]
                st.pop()

            st.append(i)

        return res