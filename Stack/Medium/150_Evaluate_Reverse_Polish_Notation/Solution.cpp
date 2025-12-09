#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>


class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::unordered_map<std::string, std::function<int(int, int)>> operations {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };
        std::stack<int> st;

        for (const std::string& oper : tokens) {
            if (!operations.contains(oper)) {
                st.push(std::stoi(oper));
            }
            else {
                int x{st.top()}; st.pop(); 
                int y{st.top()}; st.pop();        

                st.push(operations[oper](y, x));
            }
        }

        return st.top();
    }
};