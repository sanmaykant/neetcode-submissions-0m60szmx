class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int value = std::abs(nums[i]);
            if (nums[value] < 0)
                return value;
            nums[value] *= -1;
        }
    }
};
