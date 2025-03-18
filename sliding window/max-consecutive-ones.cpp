class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int zeroCount = 0;
        int left = 0, right = 0;
        int size = nums.size();

        while (right < size) {
            if (nums[right] == 0)
                zeroCount++;

            while (zeroCount > k) {
                if (nums[left] == 0)
                    zeroCount--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
