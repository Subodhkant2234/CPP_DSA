//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platform_needed = 0, result = 0;
        int n = arr.size();
        int i = 0, j = 0;
        
        while(i < n && j < n ) {
            if(arr[i] <= dep[j]){
                platform_needed++;
                i++;
            }
            else if(arr[i] > dep[j]){
                platform_needed--;
                j++;
            }
            if(platform_needed > result)
                result = platform_needed;
        }
        return result;
    }
};
