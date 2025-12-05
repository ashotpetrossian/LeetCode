#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        // Pre-allocate the vector with the final size to avoid reallocations.
        std::vector<int> result(2 * n);
        for (int i{}; i < n; ++i) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[i + n];
        }
        return result;
    }
};
