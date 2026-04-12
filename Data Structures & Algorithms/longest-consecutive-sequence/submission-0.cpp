class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        std::unordered_set<int> cache;
        for (int& num : nums)
            cache.insert(num);

        int result = 1;
        for (int i = 0; i < nums.size(); i++) {
            int cnum = nums[i];
            int length = 1;
            while (cache.count(++cnum)) {
                length++;
            }
            result = length > result ? length : result;
        }
        return result;
    }
};
