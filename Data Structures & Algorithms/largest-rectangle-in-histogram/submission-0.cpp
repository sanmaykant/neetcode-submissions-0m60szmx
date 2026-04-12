using IndexedHeight = std::pair<int, int>;

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::vector<IndexedHeight> forwardStack;
        std::vector<IndexedHeight> backwardStack;

        std::vector<IndexedHeight> indexedHeight;
        for (int i = 0; i < heights.size(); i++)
            indexedHeight.push_back({ heights[i], i });

        std::vector<int> nextSmaller(heights.size());
        std::vector<int> prevSmaller(heights.size());

        for (int i = 0; i < heights.size(); i++) {
            int j = heights.size() - i - 1;

            if (forwardStack.empty()
                || forwardStack.back().first <= heights[i])
                forwardStack.push_back({ heights[i], i });
            else {
                IndexedHeight top = forwardStack.back();
                while (!forwardStack.empty() && top.first > heights[i]) {
                    forwardStack.pop_back();
                    nextSmaller[top.second] = i - top.second;
                    if (!forwardStack.empty())
                        top = forwardStack.back();
                }
                forwardStack.push_back({ heights[i], i });
            }

            if (backwardStack.empty()
                || backwardStack.back().first <= heights[j])
                backwardStack.push_back({ heights[j], j });
            else {
                IndexedHeight top = backwardStack.back();
                while (!backwardStack.empty() && top.first > heights[j]) {
                    backwardStack.pop_back();
                    prevSmaller[top.second] = top.second - j;
                    if (!backwardStack.empty())
                        top = backwardStack.back();
                }
                backwardStack.push_back({ heights[j], j });
            }
        }

        int result = 0;
        for (int i = 0; i < heights.size(); i++) {
            int ns = nextSmaller[i] == 0 ? heights.size() - i : nextSmaller[i];
            int ps = prevSmaller[i] == 0 ? i + 1 : prevSmaller[i];
            int span = (ns - 1) + (ps - 1) + 1;
            result = std::max(result, span * heights[i]);
        }

        return result;
    }
};