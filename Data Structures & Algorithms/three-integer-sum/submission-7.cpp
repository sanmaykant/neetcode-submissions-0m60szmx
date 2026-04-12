class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            int req = -nums[i];

            if (i > 0 && nums[i-1] == nums[i])
                continue;

            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum < req || j > 0 && nums[j-1] == nums[j] && j > i + 1)
                    j++;
                else if (sum > req || k > 0 && nums[k+1] == nums[k] && k < nums.size() - 1)
                    k--;
                else if (sum == req) {
                    result.emplace_back(std::vector<int>{ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};