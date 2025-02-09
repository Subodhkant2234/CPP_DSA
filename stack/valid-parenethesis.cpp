//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool isParenthesisBalanced(string& s) {
        // code here
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else {
                    if(st.empty() == true) 
                        return false;
                    else if(s[i] == ']' && st.top() != '[')
                        return false;
                    else if(s[i] == ')' && st.top() != '(')
                        return false;
                    else if(s[i] == '}' && st.top() != '{')
                        return false;
                    else 
                        st.pop();
            }
        }
        return (st.empty() == true);
    }
};
