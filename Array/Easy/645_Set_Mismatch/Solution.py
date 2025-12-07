from typing import List


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        missing = 1
        duplicate = -1

        for num in nums:
            if nums[abs(num) - 1] < 0:
                duplicate = abs(num)
            else:
                nums[abs(num) - 1] *= -1

        for i, num in enumerate(nums, 0):
            if nums[i] > 0:
                missing = i + 1
                break

        return [duplicate, missing]