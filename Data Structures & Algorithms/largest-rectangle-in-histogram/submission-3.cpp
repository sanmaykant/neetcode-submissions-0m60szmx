class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1)
            return heights[0];

        std::unordered_map<int, int> nse, pse;
        std::stack<int> st1, st2;
        st1.push(0);
        st2.push(n - 1);

        for (int i = 1; i < n; i++) {
            int l = i;
            int r = n - i - 1;

            while (!st1.empty() && heights[l] < heights[st1.top()]) {
                nse[st1.top()] = l;
                st1.pop();
            }
            st1.push(l);

            while (!st2.empty() && heights[r] < heights[st2.top()]) {
                pse[st2.top()] = r;
                st2.pop();
            }
            st2.push(r);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            nse.try_emplace(i, n);
            pse.try_emplace(i, -1);

            int h = heights[i];
            int width = nse[i] - pse[i] - 1;
            maxArea = std::max(maxArea, width * h);
        }

        return maxArea;
    }
};
