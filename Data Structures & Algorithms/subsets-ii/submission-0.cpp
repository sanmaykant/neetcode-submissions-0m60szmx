class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> out;
        std::vector<int> sub;

        std::function<void(int)> backtrack = [&](int i) -> void {
            if (i == nums.size()) {
                out.push_back(sub);
                return;
            }
            
            sub.push_back(nums[i]);
            backtrack(i+1);

            sub.pop_back();
            while (i+1 < nums.size() && nums[i] == nums[i+1])
                i++;
            backtrack(i+1);
        };
        backtrack(0);

        return out;
    }
};
