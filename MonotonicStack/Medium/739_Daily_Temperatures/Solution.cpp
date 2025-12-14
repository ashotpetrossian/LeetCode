#include <vector>
#include <stack>


class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& vec) {
        int n = vec.size();
        std::stack<int> st;
        std::vector<int> res(n);

        for (int i{}; i < n; ++i) {
            while (!st.empty() && vec[st.top()] < vec[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return res;
    }
};