using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findMinSubArray(int S, const vector<int>& arr) {
      // TODO: Write your code here
      int len = arr.size();
      int l = 0, r = 0;
      int sum = 0;
      int subArrayLen = INT_MAX;

      while(r < len){
        sum += arr[r];
        
        while(sum >= S){
          subArrayLen = min(subArrayLen, r-l+1);
          sum = sum - arr[l];
          l++;
        }
        r++;
      }
      return subArrayLen == INT_MAX ? 0 : subArrayLen;
    }
  };
