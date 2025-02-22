using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  vector<int> sort(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      int j = nums[i] - 1;  // Calculate the index where the current element should be placed.
      if (nums[i] != nums[j]) {  // Check if the current element is not in its correct position.
        swap(nums, i, j);  // Swap the current element with the one at its correct position.
      } else {
        i++;  // If the current element is already in its correct position, move to the next element.
      }
    }
    return nums;
  }

private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};
