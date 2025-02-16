//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int  count = 0;
        while(n > 0){
            n = n & (n-1);
            count++;
        }
        return  count;
    }
};
