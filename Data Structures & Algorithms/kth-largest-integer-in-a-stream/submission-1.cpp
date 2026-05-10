class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for (int i = 0; i < std::min(k, (int) nums.size()); i++)
            minHeap.push(nums[i]);
    }

    int add(int val) {
        if (k > minHeap.size()) {
            minHeap.push(val);
            return minHeap.top();
        }
        minHeap.push(val);
        minHeap.pop();
        std::cout << minHeap.size();
        return minHeap.top();
    }

private:
    int k = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
}; 