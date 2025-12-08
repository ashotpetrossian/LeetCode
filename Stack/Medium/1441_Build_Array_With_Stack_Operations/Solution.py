from typing import List


class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res = []
        j = 0

        for i in range(1, n + 1):
            res.append("Push")
            if i != target[j]:
                res.append("Pop")
            else:
                j += 1

            if j == len(target):
                break

        return res