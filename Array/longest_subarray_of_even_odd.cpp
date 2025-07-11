// User function Template for C++

class Solution {
  public:
    // Complete this function
    // Function to find the length of longest subarray of even and odd numbers.
    int maxEvenOdd(int arr[], int n) {
        // Your code here
        int res = 1, curr = 1;
        for(int i = 1; i < n; i++){
            if((arr[i-1]%2 == 0 && arr[i]%2 != 0) ||(arr[i-1]%2 != 0 && arr[i] %2 == 0)){
                curr++;
                res = max(res, curr);
            } else {
                curr = 1;
            }
        }
        return res;
    }
};
