class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int val = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                count++;
                val = max(count, val);
            } else {
                count = 0;
            }
        }
        return val;
    }
};
