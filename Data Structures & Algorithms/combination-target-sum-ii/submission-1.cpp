class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> out;
        std::unordered_map<int, int> numFreq;
        std::unordered_set<int> unique_nums;

        for (int num : candidates) {
            numFreq.try_emplace(num, 0);
            numFreq[num]++;
            unique_nums.insert(num);
        }
        std::vector<int> nums(unique_nums.begin(), unique_nums.end());
        std::sort(nums.begin(), nums.end());

        int sum = 0;
        std::vector<int> subset;
        std::function<void(int)> dfs = [&](int i) {
            if (sum == target)
                out.push_back(subset);
            if (sum >= target || i == nums.size())
                return;

            if (numFreq[nums[i]]) {
                numFreq[nums[i]]--;
                
                subset.push_back(nums[i]);
                sum += nums[i];
                dfs(i);
                
                numFreq[nums[i]]++;
                subset.pop_back();
                sum -= nums[i];
            }

            dfs(i + 1);
        };
        dfs(0);

        return out;
    }
};
