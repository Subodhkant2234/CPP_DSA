using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  vector<int> sort(vector<int> &arr) {
    // TODO: Write your code here
    int low = -1;
    int mid = 0;
    int high = arr.size()-1;

    while(mid <= high){
      if(arr[mid] == 0){
        low++;
        swap(arr[mid], arr[low]);
        mid++;
      } 
      else if(arr[mid] == 1){
        mid++;
      } else {
        swap(arr[mid], arr[high]);
        high--;
      }
    }
    return arr;
  }
};
