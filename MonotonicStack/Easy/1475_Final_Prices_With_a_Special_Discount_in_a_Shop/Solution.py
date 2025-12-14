from typing import List


class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        res = prices[:]
        st = []

        for i, price in enumerate(prices):
            while st and price <= prices[st[-1]]:
                res[st[-1]] -= price
                st.pop()

            st.append(i)

        return res