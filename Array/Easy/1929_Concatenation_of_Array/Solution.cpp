#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};