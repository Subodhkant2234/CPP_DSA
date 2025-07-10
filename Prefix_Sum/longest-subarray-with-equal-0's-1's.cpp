class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unorded_map<int, int> mp;
        int presum = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            presum += (nums[i] == 0) ? -1 : 1;
            if (presum == 0) {
                res = i + 1;
            }
            if (mp.find(presum) != mp.end()) {
                res = max(res, i - mp[presum]);
            } else {
                mp[presum] = i;
            }
        }
        return res;
    }
};
