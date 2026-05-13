class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (int num : nums) {
            if (minHeap.size() == k) {
                minHeap.push(num);
                minHeap.pop();
            } else
                minHeap.push(num);
        }
        return minHeap.top();
    }
};
