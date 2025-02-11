//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int res = 0;;
        int l = 0, r = 0;
        int count[256] = {0};
        
        while(r < s.length()){
            count[s[r]]++;
            while(count[s[r]] > 1){
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
