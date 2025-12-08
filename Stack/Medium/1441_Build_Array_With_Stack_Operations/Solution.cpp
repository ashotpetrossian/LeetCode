#include <vector>
#include <string>


class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> res;

        for (int i{1}, j{}; i <= n && j < target.size(); ++i) {
            res.push_back("Push");
            if (i != target[j]) {
                res.push_back("Pop");
            }
            else {
                ++j;
            }
        }

        return res;
    }
};