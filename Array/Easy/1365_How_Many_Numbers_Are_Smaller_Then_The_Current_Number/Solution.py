from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        maxElement = max(nums)
        vec = [0] * (maxElement + 1)
        for num in nums:
            vec[num] += 1

        for i in range(1, maxElement + 1):
            vec[i] += vec[i - 1]

        for i, num in enumerate(nums, 0):
            nums[i] = 0 if num == 0 else vec[num - 1]

        return nums