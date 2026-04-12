class Solution {
    public:
        bool hasDuplicate(const std::vector<int>& nums) {
            std::unordered_set<int> seen;
            for (const int& num: nums) {
                if (seen.count(num))
                    return true;
                seen.insert(num);
            }
            return false;
        }
};