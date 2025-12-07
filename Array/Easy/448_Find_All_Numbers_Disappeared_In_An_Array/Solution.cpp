#include <vector>


class Solution {
public:    
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int i{}, n = nums.size();
        while (i < n) {
            if (nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                ++i;
            }
        }

        std::vector<int> res;
        for (int i{}; i < n; ++i) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};