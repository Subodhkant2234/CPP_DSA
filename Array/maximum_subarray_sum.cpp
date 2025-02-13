//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int maxEnding = arr[0];
        int res = arr[0];
        for(int i = 1; i < arr.size(); i++){
            maxEnding = max(maxEnding+arr[i], arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
};
