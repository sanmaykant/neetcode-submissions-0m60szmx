class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (int i = 0; i < strs.size(); i++) {
            int freqs[26] = {0};
            for (char& c : strs[i]) {
                freqs[c - 'a']++;
            }

            std::string key = std::to_string(freqs[0]);
            for (int j = 1; j < 26; j++) {
                key += ',' + std::to_string(freqs[j]);
            }

            groups.try_emplace(key, std::vector<std::string>{});
            groups[key].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> returnable;
        for (auto& [_, value] : groups) {
            returnable.push_back(value);
        }
        return returnable;
    }
};
