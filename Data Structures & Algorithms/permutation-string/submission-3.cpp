class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::unordered_map<char, int> s1Freq;
        std::unordered_map<char, int> s2Freq;

        for (int i = 0; i < s1.size(); i++) {
            s1Freq.try_emplace(s1[i], 0);
            s2Freq.try_emplace(s2[i], 0);
            s1Freq[s1[i]]++;
            s2Freq[s2[i]]++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            s1Freq.try_emplace(i + 'a', 0);
            s2Freq.try_emplace(i + 'a', 0);
            if (s1Freq[i + 'a'] == s2Freq[i + 'a'])
                matches++;
        }

        if (matches == 26)
            return true;

        int i = 0;
        int j = s1.size() - 1;
        while (i < j && j < s2.size()) {
            bool matchedPreviously = false;

            matchedPreviously = s1Freq[s2[i]] == s2Freq[s2[i]];
            s2Freq[s2[i]]--;
            i++;

            if (s1Freq[s2[i-1]] != s2Freq[s2[i-1]] && matchedPreviously)
                matches--;
            else if (s1Freq[s2[i-1]] == s2Freq[s2[i-1]])
                matches++;

            matchedPreviously = s1Freq[s2[j+1]] == s2Freq[s2[j+1]];
            j++;
            s2Freq[s2[j]]++;

            if (s1Freq[s2[j]] == s2Freq[s2[j]])
                matches++;
            else if (s1Freq[s2[j]] != s2Freq[s2[j]] && matchedPreviously)
                matches--;

            if (matches == 26)
                return true;
        }
        return false;
    }
};
