from typing import List


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        i = 0
        n = len(nums)
        
        while i < n:
            correct_index = nums[i] - 1
            if nums[i] != nums[correct_index]:
                # Swap the number to its correct position
                nums[i], nums[correct_index] = nums[correct_index], nums[i]
            else:
                i += 1  
        
        missing_numbers = []
        for i, num in enumerate(nums):
            if num != i + 1:
                missing_numbers.append(i + 1)

        return missing_numbers
                