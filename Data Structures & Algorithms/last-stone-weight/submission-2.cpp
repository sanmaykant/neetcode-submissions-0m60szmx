class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxHeap;
        for (int w : stones)
            maxHeap.push(w);

        while (maxHeap.size() >= 2) {
            int w1 = maxHeap.top();
            maxHeap.pop();
            int w2 = maxHeap.top();
            maxHeap.pop();

            if (w1 != w2)
                maxHeap.push(std::abs(w1 - w2));
        }

        if (!maxHeap.empty())
            return maxHeap.top();
        else
            return 0;
    }
};
