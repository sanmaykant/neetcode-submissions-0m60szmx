class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};

        static std::unordered_map<char, std::string> intToStr = {
            { '2', "abc"  },
            { '3', "def"  },
            { '4', "ghi"  },
            { '5', "jkl"  },
            { '6', "mno"  },
            { '7', "pqrs" },
            { '8', "tuv"  },
            { '9', "wxyz" },
        };
        

        std::vector<std::string> out;

        std::string s = ""; 
        std::function<void(int)> backtrack = [&](int i) -> void {
            if (i == digits.size()) {
                out.push_back(s);
                return;
            }

            for (char c : intToStr[digits[i]]) {
                s.push_back(c);
                backtrack(i + 1);
                s.pop_back();
            }
        }; 
        backtrack(0);

        return out;
    }
};
