#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If stack is empty, it means no matching opening bracket
                if (st.empty()) return false;
                char top = st.top(); st.pop(); // Get the top element of the stack
                // Check if the current closing bracket matches the top of the stack
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        // If stack is empty, all brackets were matched
        return st.empty();
    }
};
