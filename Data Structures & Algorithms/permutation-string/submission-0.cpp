#include <array>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::unordered_set<std::string> cache;

        std::array<int, 26> bucket = {0};
        std::string key = "";

        for (char& c : s1)
            bucket[std::tolower(c) - 'a']++;
        for (int i = 0; i < bucket.size(); i++) {
            key += std::to_string(bucket[i]);
            bucket[i] = 0;
        }

        cache.insert(key);
        key = "";

        for (int i = 0; i < s1.size(); i++)
            bucket[std::tolower(s2[i]) - 'a']++;
        for (int i = 0; i < bucket.size(); i++)
            key += std::to_string(bucket[i]);

        if (cache.count(key))
            return true;
        key = "";

        int i = 0;
        int j = s1.size() - 1;
        while (i < j && j < s2.size() - 1) {
            bucket[std::tolower(s2[i]) - 'a']--;
            i++;
            j++;
            bucket[std::tolower(s2[j]) - 'a']++;

            for (int i = 0; i < bucket.size(); i++)
                key += std::to_string(bucket[i]);
            if (cache.count(key))
                return true;
            key = "";
        }
        return false;
    }
};