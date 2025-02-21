#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        // Continue until the search range is exhausted
        while (left < right) {
            int mid = left + (right - left) / 2;  // Finding the middle index
            
            // If mid element is greater than the rightmost element, the minimum is on the right
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;  // Otherwise, the minimum is on the left or at mid
            }
        }
        return nums[left];  // Return the smallest element
    }
};

