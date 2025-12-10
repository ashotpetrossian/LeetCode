#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortByAbsoluteValue(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return std::abs(a) < std::abs(b);
        });

        return nums;
    }
};