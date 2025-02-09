//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string &s) {
        // Your code here
        stack<char> st;
        string res;
        for(char ch : s){
            if(st.empty()){
                st.push(ch);
            } else {
                if(st.top() != ch)
                    st.push(ch);
            }
            
        }
        while(st.empty() == false){
            res = res + st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
