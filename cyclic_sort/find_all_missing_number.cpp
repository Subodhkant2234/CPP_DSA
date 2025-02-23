using namespace std;

#include <iostream>
#include <vector>

class Solution {
public: 
  void swap(vector<int> &arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }

  vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    int i = 0;
    // TODO: Write your code here
    while(i < nums.size()){
      int correctIndex = nums[i]-1;
      if(nums[i] != nums[correctIndex]){
        swap(nums, i, correctIndex);
      } else {
        i++;
      }
    }
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] != i+1)
        missingNumbers.push_back(i+1);
    }  
    return missingNumbers;
  }
};
