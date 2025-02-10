using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    int findSingleNumber(const vector<int>& arr) {
      int num = 0;
      // TODO: Write your code here
      for(int x : arr){
        num ^= x;
      }
      return num;
    }
};
