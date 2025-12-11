#include <string>
#include <tuple>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

class Solution {
private:
    std::tuple<int, bool, int> getInfo(const std::string& s) {
        size_t first_colon{s.find(':')};
        int id{std::stoi(s.substr(0, first_colon))};

        size_t second_colon{s.find(':', first_colon + 1)};
        bool isStart{s[first_colon + 1] == 's'};

        std::string time_str{s.substr(second_colon + 1)};
        int time{std::stoi(time_str)};
        
        return std::make_tuple(id, isStart, time);
    }

public:
    std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
        std::vector<int> res(n);
        std::stack<int> st;

        auto [prevId, prevIsStart, prevTime] = getInfo(logs.front());
        st.push(prevId);

        for (int i{1}, len = (int)logs.size(); i < len; ++i) {
            auto [id, isStart, time] = getInfo(logs[i]);
            
            if (isStart) {
                if (!st.empty()) {
                    res[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } else {
                res[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return res;
    }
};