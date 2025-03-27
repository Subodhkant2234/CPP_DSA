class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                int top = st.top();
                st.pop();
                if (s[i] == ')' && top != '(')
                    return false;
                if (s[i] == ']' && top != '[')
                    return false;
                if (s[i] == '}' && top != '{')
                    return false;
            }
        }
        return st.empty();
    }
};
