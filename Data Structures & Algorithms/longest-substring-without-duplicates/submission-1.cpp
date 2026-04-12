class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 1 || s.size() == 0)
            return s.size();

        std::unordered_map<char, int> cache;
        cache[s[0]] = 0;

        int l = 0;
        int r = 1;
        int maxSize = 1;

        while (r < s.size()) {
            if (!cache.count(s[r])) {
                cache[s[r]] = r;
                maxSize = std::max(r - l + 1, maxSize);
                r++;
            } else {
                l = cache[s[r]] + 1;
                r = l + 1;
                cache.clear();
                cache[s[l]] = l;
            }
        }

        return maxSize;
    }
};