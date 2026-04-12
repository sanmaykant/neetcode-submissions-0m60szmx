class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::vector<int> st;
        int maxArea = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int currHeight = i == heights.size() ? 0 : heights[i];
            while (!st.empty() && currHeight < heights[st.back()]) {
                int height = heights[st.back()];
                st.pop_back();
                int width = st.empty() ? i : i - st.back() - 1;
                maxArea = std::max(maxArea, width * height);
            }
            st.push_back(i);
        }
        return maxArea;
    }
};