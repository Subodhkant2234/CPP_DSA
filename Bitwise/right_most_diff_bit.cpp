//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int x = m ^ n;
        int pos = 1;
        while(x){
            
            if(x & 1)
                return pos;
            pos++;
            x = x >> 1;
        }
        return -1;
    }
};
