//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    typedef long long int ll;

    long long int minValue(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n = arr1.size();
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        long long res = 0;
        for(int i = 0; i < n; i++){
            res += (arr1[i] * arr2[n-i-1]);
        }
        return res;
    }
};
