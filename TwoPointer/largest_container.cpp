//https://www.geeksforgeeks.org/problems/container-with-most-water0535/1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;  // To store the maximum area found
        int res = 0;
        // ToDo: Write Your Code Here.
        int left = 0, right = height.size()-1;
        while(left < right){
            res = min(height[left], height[right]) * (right-left);
            maxArea = max(res, maxArea);
            if(height[left] < height[right])
                left++;
            else if( height[left] > height[right])
                right--;
            else {
                left++;
                right--;
            }
        }
        return maxArea;
    }
};
