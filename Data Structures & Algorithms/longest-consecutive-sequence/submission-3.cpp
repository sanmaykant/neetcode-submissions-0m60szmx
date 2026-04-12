class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        std::unordered_set<int> cache;
        for (int num : nums)
            cache.insert(num);
        
        int length = 1, maxLength = 1;
        for (int num : nums) {
            while (cache.count(--num))
                length++;
            maxLength = std::max(maxLength, length);
            length = 1;
        }

        return maxLength;
    }
};
