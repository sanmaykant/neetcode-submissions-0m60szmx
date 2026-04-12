class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> st;
        for (std::string& token : tokens) {
            if (!(token == "+" || token == "-" || token == "*" || token == "/"))
                st.push_back(std::stoi(token));
            else {
                int op2 = st.back();
                st.pop_back();
                int op1 = st.back();
                st.pop_back();
                int result;

                switch (token[0]) {
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': result = op1 / op2; break;
                }

                st.push_back(result);
            }
        }
        return (int) st.back();
    }
};