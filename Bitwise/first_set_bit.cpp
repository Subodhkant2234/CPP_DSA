//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to find position of first set bit in the given number.
    int getFirstSetBit(int n) {
        // Your code here
        int pos = 1;
        while(n){
            if(n & 1)
                return pos;
            pos++;
            n = n >> 1;
        }
    }
};
