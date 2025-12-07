#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        int max{*(std::max_element(nums.begin(), nums.end()))};
        std::vector<int> vec(max + 1);
        for (int i : nums) ++vec[i];
        
        for (int i{1}; i <= max; ++i) vec[i] += vec[i - 1];
        for (int i{}; i < nums.size(); ++i) {
            nums[i] = nums[i] == 0 ? 0 : vec[nums[i] - 1];
        }

        return nums;
    }
};