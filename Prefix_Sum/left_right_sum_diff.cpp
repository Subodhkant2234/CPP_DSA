#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDifferenceArray(const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> differenceArray(n);
        int leftSum = 0;
        int rightSum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            rightSum += num;
        }

        // Calculate the difference between left and right sums for each position
        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            differenceArray[i] = std::abs(rightSum - leftSum);
            leftSum += nums[i];
        }

        return differenceArray;
    }
};


