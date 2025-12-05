#include <vector>
#include <algorithm>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max_count{};
        int current_count{};
        for (int num : nums) {
            if (num == 1) {
                ++current_count;
            } else {
                // When we see a 0, the streak is broken.
                // Update the max count and reset the current one.
                max_count = std::max(max_count, current_count);
                current_count = 0;
            }
        }
        // Final check in case the longest sequence is at the very end.
        return std::max(max_count, current_count);
    }
};
