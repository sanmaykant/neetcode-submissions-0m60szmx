#include <array>

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encodedString = "";
        for (std::string& str : strs)
            encodedString += std::to_string(str.length()) + "#" + str;
        return encodedString;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded;
        int beg = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                std::istringstream iss(s.substr(beg, i - beg));
                int strLen;
                iss >> strLen;

                decoded.push_back(s.substr(i+1, strLen));
                beg = i + 1 + strLen;
                i = i + strLen;
            }
        }
        return decoded;
    }
};
