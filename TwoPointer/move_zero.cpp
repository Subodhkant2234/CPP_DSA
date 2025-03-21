class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        for (int i = 0; i < right; i++) {
            if (nums[i] != 0) {
                swap(nums[left], nums[i]);
                left++;
            }
        }
    }
};
