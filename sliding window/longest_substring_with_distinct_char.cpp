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



class Solution {
   public:
    int longestNonRepeatingSubstring(string& s) {
        int windowStart = 0;
        unordered_map<char, int> mp;
        int maxLen = 0;

        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            char right = s[windowEnd];
            if (mp.find(right) != mp.end() && mp[right] >= windowStart) {
                windowStart = mp[right] + 1;
            }

            mp[right] = windowEnd;

            maxLen = max(maxLen, windowEnd - windowStart + 1);
        }
        return maxLen;
    }
};
