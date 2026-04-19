class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> out;

        std::vector<int> selection;
        int sum = 0;
        std::function<void(int)> dfs = [&](int i) {
            if (sum == target)
                out.push_back(selection);
            if (sum >= target || i == nums.size())
                return;

            selection.push_back(nums[i]);
            sum += nums[i];
            dfs(i);

            selection.pop_back();
            sum -= nums[i];
            dfs(i + 1);
        };
        dfs(0);

        return out;
    }
};
