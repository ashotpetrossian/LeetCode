#include <vector>

class Solution {
public:
    bool checkXMatrix(std::vector<std::vector<int>>& grid) {
        for (int i{}, n = grid.size(); i < n; ++i) {
            for (int j{}; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) return false;
                }
                else if (grid[i][j] > 0) return false;
            }
        }

        return true;
    }
};