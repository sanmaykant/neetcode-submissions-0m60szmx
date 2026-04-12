class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t.size() > s.size())
            return "";
        if (t.size() == 1) {
            return s.find(t) == std::string::npos ? "" : t;
        }

        std::unordered_map<char, int> tFreq;
        std::unordered_map<char, int> wFreq;

        for (int i = 0; i < t.size(); i++) {
            tFreq.try_emplace(t[i], 0);
            tFreq[t[i]]++;
        }

        int i = 0;
        int j = 0;
        int matches = 0;
        int reqMatches = tFreq.size();
        int minLen = s.size() + 1;
        std::string shortestString = "";

        do {
            if (matches != reqMatches) {
                if (tFreq.count(s[j])) {
                    wFreq[s[j]]++;
                    if (wFreq[s[j]] == tFreq[s[j]])
                        matches++;
                }
                j++;
            } else {
                if (j - i < minLen) {
                    minLen = j - i;
                    shortestString = s.substr(i, minLen);
                }
                if (tFreq.count(s[i])) {
                    if (wFreq[s[i]] == tFreq[s[i]])
                        matches--;
                    wFreq[s[i]]--;
                }
                i++;
            }
        } while (i < j && j < s.size() + 1);

        return shortestString;
    }
};