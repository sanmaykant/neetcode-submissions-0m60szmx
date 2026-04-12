class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        std::vector<std::vector<int>> freqs(nums.size() + 1);

        for (int& num : nums) {
            count.try_emplace(num, 0);
            count[num]++;
        }

        for (auto& [value, freq] : count) {
            freqs[freq].push_back(value);
        }

        std::vector<int> result;
        for (int i = freqs.size() - 1; i >= 0; i--) {
            std::vector<int>& values = freqs[i];
            for (int& value : values) {
                result.push_back(value);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
