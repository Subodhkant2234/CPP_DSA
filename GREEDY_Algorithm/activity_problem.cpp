//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    static bool mycom(pair<int, int> a, pair<int, int> b){
        return (a.second < b.second);
    }
    
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int, int>>arr;
        for(int i = 0; i < start.size(); i++){
            arr.push_back(make_pair(start[i],finish[i]));
        }
        sort(arr.begin(), arr.end(), mycom);
        int res = 1;
        int prev = 0;
        for(int curr = 1; curr < n; curr++){
            if(arr[curr].first > arr[prev].second){
                res++;
                prev = curr;
            }
        }
        return res;
    }
};
