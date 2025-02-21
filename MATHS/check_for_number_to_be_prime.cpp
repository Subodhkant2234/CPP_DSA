//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPrime(int n) {
        // code here
        int count = 0;
        if(n <= 1)
            return false;
        // Check how many numbers divide n in
        // range 2 to sqrt(n)
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0)
                count++;
            if(count > 0)
                return false;
        }
        return true;
    }
};
