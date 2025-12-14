#include <vector>
#include <stack>


class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<int> res(prices);
        std::stack<int> st;

        for (int i{}; i < n; ++i) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                res[st.top()] -= prices[i];
                st.pop();
            }

            st.push(i);
        }

        return res;
    }
};