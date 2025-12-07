#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int missing{1}, duplicate{-1};
        
        for (int num : nums) {
            if (nums[std::abs(num) - 1] < 0) duplicate = std::abs(num);
            else nums[std::abs(num) - 1] *= -1;
        }

        for (int i{}, n = nums.size(); i < n; ++i) {
            if (nums[i] > 0) {
                missing = i + 1;  
                break;
            }
        }   

        return std::vector{duplicate, missing};
    }
};