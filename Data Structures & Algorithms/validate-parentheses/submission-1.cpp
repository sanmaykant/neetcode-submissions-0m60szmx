class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        std::unordered_map<char, char> m = {
            { '(', ')' },
            { '[', ']' },
            { '{', '}' },
        };
        for (char& c : s) {
            if (m.count(c))
                st.push(m[c]);
            else if (!st.empty() && st.top() == c)
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};
