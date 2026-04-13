class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1)
            return heights[0];

        std::stack<int> st;
        st.push(0);

        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            int currentHeight = i == n ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > currentHeight) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(maxArea, width * h);
            }
            st.push(i);
        }

        return maxArea;
    }
};
