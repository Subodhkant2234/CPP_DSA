#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // Calculate the total sum of all elements in the array
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        // Initialize the sum of elements to the left
        int leftSum = 0;
        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the sum of elements to the right
            int rightSum = totalSum - leftSum - nums[i];
            // Check if the sum of elements to the left equals the sum of elements to the right
            if (leftSum == rightSum) {
                return i;
            }
            // Update the sum of elements to the left
            leftSum += nums[i];
        }
        return -1;
    }
};
