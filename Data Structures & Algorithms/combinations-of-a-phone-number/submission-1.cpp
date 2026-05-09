class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};

        static std::vector<std::string> intToStr = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        }; 

        std::vector<std::string> out;

        std::string s = ""; 
        std::function<void(int)> backtrack = [&](int i) -> void {
            if (i == digits.size()) {
                out.push_back(s);
                return;
            }

            for (char c : intToStr[digits[i] - '0']) {
                s.push_back(c);
                backtrack(i + 1);
                s.pop_back();
            }
        }; 
        backtrack(0);

        return out;
    }
};
