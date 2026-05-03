class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> out;
        std::string s;

        std::stack<char> st;
        std::function<void()> backtrack = [&]() -> void {
            if (s.size() == 2 * n) {
                if (st.empty())
                    out.push_back(s);
                return;
            }
            
            s += '(';
            st.push('(');
            backtrack();

            s.erase(--s.end());
            st.pop();

            if (!st.empty()) {
                s += ')';
                st.pop();
                backtrack();

                s.erase(--s.end());
                st.push('(');
            }
        };
        backtrack();

        return out;
    }
};
