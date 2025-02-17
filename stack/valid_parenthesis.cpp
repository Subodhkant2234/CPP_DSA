class Solution {
public:
    bool match_func(char a, char b) {
        if ((a == '[' && b == ']') || (a == '{' && b == '}') ||
            (a == '(' && b == ')')) {
            return true;
        } else {
            return false;
        }
    }
    bool isValid(string s) {
        // ToDo: Write Your Code Here.
        int n = s.length();
        int i = 0;
        stack<int> st;

        while (i < n) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                i++;
            }

            while (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (st.empty())
                    return false;

                if (!match_func(st.top(), s[i]))
                    return false;
                i++;
                st.pop();
            }
        }
        if (st.empty() == false)
            return false;
        return true;
    }
};
