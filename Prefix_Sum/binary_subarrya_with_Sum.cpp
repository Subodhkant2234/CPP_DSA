https://leetcode.com/problems/binary-subarrays-with-sum/description/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case: one way to get sum 0
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            if (prefixCount.find(sum - goal) != prefixCount.end()) {
                count += prefixCount[sum - goal];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};
