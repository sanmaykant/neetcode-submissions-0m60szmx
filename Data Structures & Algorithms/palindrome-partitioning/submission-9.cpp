class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> out;
        std::vector<std::string> candidate;

        std::function<void(int)> backtrack = [&](int b) -> void {
            if (b == s.size()) {
                out.push_back(candidate);
                return;
            }

            for (int l = 1; l <= s.size() - b; l++) {
                if (!isPalindrome(s.substr(b, l)))
                    continue;
                candidate.push_back(s.substr(b, l));
                backtrack(b + l);
                candidate.pop_back();
            }
        };
        backtrack(0);

        return out;
    }

private:
    bool isPalindrome(std::string_view s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
