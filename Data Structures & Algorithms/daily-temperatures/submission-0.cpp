#include <array>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        if (temperatures.size() == 1)
            return std::vector<int>{ 0 };

        std::vector<std::array<int, 2>> st;
        std::vector<int> result(temperatures.size());

        st.push_back({ temperatures[0], 0 });
        for (int i = 1; i < temperatures.size(); i++) {
            int& temp = temperatures[i];
            if (temp <= st.back()[0])
                st.push_back({ temp, i });
            else {
                while (true) {
                    if (st.empty()) {
                        st.push_back({ temp, i });
                        break;
                    }

                    auto [top, j] = st.back();
                    if (top < temp) {
                        st.pop_back();
                        result[j] = i - j;
                    } else {
                        st.push_back({ temp, i });
                        break;
                    }
                }
            }
        }

        return result;
    }
};