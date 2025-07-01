/* https://takeuforward.org/plus/dsa/problems/max-consecutive-ones-ii */
/* Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0. */
class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Your code goes here
        int zeros = 0;
        int cnt = 0;
        int l = 0, r = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }
            while (zeros > 1) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }
            cnt = max(cnt, r - l + 1);
            r++;
        }
        return cnt;
    }
};
