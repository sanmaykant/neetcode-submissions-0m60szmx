class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 1 || s.size() == 0)
            return s.size();

        std::unordered_set<char> cache;
        cache.insert(s[0]);

        int l = 0;
        int r = 1;
        int maxSize = 1;

        while (r < s.size()) {
            if (!cache.count(s[r])) {
                cache.insert(s[r]);
                maxSize = std::max(r - l + 1, maxSize);
                r++;
            } else {
                cache.erase(s[l]);
                l++;
            }
        }

        return maxSize;
    }
};