class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            unordered_map<int, int> mp;
            int n = nums.size();
            for (auto val : nums) {
                mp[val]++;
            }
            n = n / 2;
            for (auto x : mp) {
                if (x.second > n)
                    return x.first;
            }
            return 0;
        */
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};
