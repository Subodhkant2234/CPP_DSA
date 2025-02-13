using namespace std;

#include <iostream>
#include <vector>

class Solution {

  public:

  static vector<int> search(const vector<int> &arr, int targetSum) {
    // TODO: Write your code here
    int l = 0, r = arr.size() - 1;
    vector<int> v(2,-1);

    while(l < r)
    {
      if(arr[l] + arr[r] == targetSum){
        v[0] = l;
        v[1] = r;
        return v;
      }
      else if(arr[l] + arr[r] > targetSum){
        r--;
      } else {
        l++;
      }
    }
    return v;
  }

};
