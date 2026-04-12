class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;

        int max = 0;
        while (i < j) {
            int maxEstimate = std::min(heights[i], heights[j]) * std::abs(i - j);
            if (heights[i] <= heights[j])
                i++;
            else
                j--;
            max = std::max(maxEstimate, max);
        }
        return max;
    }
};
