class Solution {
public:
    int characterReplacement(std::string s, int k) {
        if (s.size() == 0 || s.size() == 1)
            return s.size();

        if (k == 0) {
            int i = 0;
            int j = 1;

            if (s[i] != s[j]) {
                i++;
                j++;
            }

            int maxLength = 1;
            while (i < j && j < s.size()) {
                if (s[i] == s[j]) {
                    maxLength = std::max(maxLength, j - i + 1);
                    j++;
                } else {
                    i = j;
                    j = i + 1;
                }
            }
            return maxLength;
        }

        int i = 0;
        int j = 1;
        int maxFreq = 1;
        int maxLength = 1;

        std::unordered_map<char, int> cache;
        cache[s[0]] = 1;

        while (i < j && j < s.size()) {
            cache.try_emplace(s[j], 0);
            cache[s[j]]++;

            if (cache[s[j]] > maxFreq)
                maxFreq = cache[s[j]];

            int reqRepl = j - i + 1 - maxFreq;
            if (reqRepl <= k) {
                maxLength = std::max(maxLength, j - i + 1);
            } else {
                cache[s[i]]--;
                i++;
            }
            j++;
        }

        return maxLength;
    }
};