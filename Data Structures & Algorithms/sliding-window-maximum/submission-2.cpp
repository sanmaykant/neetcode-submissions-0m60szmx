class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if (k == 1)
            return nums;

        std::unordered_map<int, int> cache;
        std::vector<int> result;

        int maxElem = nums[0];
        for (int i = 0; i < k; i++) {
            cache.try_emplace(nums[i], 0);
            cache[nums[i]]++;
            if (nums[i] > maxElem)
                maxElem = nums[i];
        }
        result.push_back(maxElem);

        if (nums.size() == k)
            return result;

        int i = 0;
        int j = k - 1;
        while (j < nums.size()) {
            cache[nums[i]]--;
            i++;
            j++;
            if (j == nums.size())
                break;
            cache.try_emplace(nums[j], 0);
            cache[nums[j]]++;

            if (nums[j] > maxElem)
                maxElem = nums[j];
            else if (cache[maxElem] > 0)
                maxElem = maxElem;
            else {
                int winMaxElem = nums[i];
                for (int k = i; k <= j; k++)
                    if (nums[k] > winMaxElem)
                        winMaxElem = nums[k];
                maxElem = winMaxElem;
            }

            result.push_back(maxElem);
        }

        return result;
    }
};