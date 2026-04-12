class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int jVal = target - nums[i];
            if (seen.count(jVal)) {
                return { seen[jVal], i };
            }
            seen[nums[i]] = i;
        }
    }
};
