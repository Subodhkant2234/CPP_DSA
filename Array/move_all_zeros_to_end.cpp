//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int l = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != 0){
                swap(arr[i], arr[l]);
                l++;
            }
        }
    }
};
