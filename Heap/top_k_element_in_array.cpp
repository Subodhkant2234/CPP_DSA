#https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/top-k-numbers-easy
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    // TODO: Write your code here
    vector<int>v;
   priority_queue <int, vector<int>, greater<int>>  minHeap;
    for(int i = 0; i < k; i++)
      minHeap.push(nums[i]);

    for(int i = k; i < nums.size(); i++){
      if(nums[i] > minHeap.top()){
        minHeap.pop();
        minHeap.push(nums[i]);
      }
    }
    for(int i = 0; i < k; i++){
      v.push_back(minHeap.top());
      minHeap.pop();
    }
    return v;
  }
};
