using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  int rightMostSetBit(int num){
    int pos = 1;
    while(num > 0){
    if(num & 1)
      return pos;
      pos++;
      num = num >> 1;
    }
  }

  vector<int> findSingleNumbers(vector<int> &nums) {
    // TODO: Write your code here
    vector<int> zeros;
    vector<int> ones;
    vector<int> res;

    int pos = 0;
    int val = 0;
    for (int x : nums){
      val ^= x;
    }
    pos = rightMostSetBit(val);
    int mask = 1 << (pos-1);

    for(int x : nums){
    if(x & mask)
      ones.push_back(x);
    else 
      zeros.push_back(x);
    }
    
    int num1 = 0;
    int num2 = 0;
    for(int x : zeros){
      num1 ^= x;
    }

    for(int x : ones){
      num2 ^= x;
    }

    res.push_back(num1);
    res.push_back(num2);
    return res;
    
  }
};
