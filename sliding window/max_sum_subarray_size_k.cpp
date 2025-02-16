using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMaxSumSubArray(int k, const vector<int>& arr) {
      // TODO: Write your code here
      int l = 0, r = 0;
      int sum = 0;
      int maxSum = 0;
      int n = arr.size();

      while(r < n){
        sum += arr[r];
        if(r-l+1 == k){
          maxSum = max(maxSum, sum);
          sum = sum-arr[l];
          l++;
        }
        r++;
      }
      return maxSum;
    }
  };        
