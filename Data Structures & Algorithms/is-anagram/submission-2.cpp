class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> freq;

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            char& sc = s[i];
            char& tc = t[i];

            freq.try_emplace(sc, 0);
            freq.try_emplace(tc, 0);

            freq[sc]++;
            freq[tc]--;
        }

        for (auto& [key, value] : freq) {
            if (value != 0)
                return false;
        }
        return true;
    }
};
