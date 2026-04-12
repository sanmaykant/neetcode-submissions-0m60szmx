class Solution {
public:
    int trap(vector<int>& height) {
        std::unordered_map<int, std::vector<int>> heightCache;
        
        int leftMaxHeight = 0;
        int rightMaxHeight = 0;
        for (int i = 0; i < height.size(); i++) {
            int j = height.size() - 1 - i;

            heightCache.try_emplace(i + 1, std::vector<int>{ 0, 0 });
            heightCache.try_emplace(j - 1, std::vector<int>{ 0, 0 });

            leftMaxHeight = std::max(height[i], leftMaxHeight);
            rightMaxHeight = std::max(height[j], rightMaxHeight);

            if (i < height.size() - 1)
                heightCache[i + 1][0] = leftMaxHeight;
            if (j > 0)
                heightCache[j - 1][1] = rightMaxHeight;
        }


        int area = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int leftMaxHeight = heightCache[i][0];
            int rightMaxHeight = heightCache[i][1];
            int minHeight = std::min(leftMaxHeight, rightMaxHeight);
            int waterAtI = std::max(minHeight - height[i], 0);
            area += waterAtI;
        }
        return area;
    }
};
