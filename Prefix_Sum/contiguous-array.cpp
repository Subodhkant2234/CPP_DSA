class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0, res = 0;
        unordered_map<int, int> diffIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero++;
            } else {
                one++;
            }

            int diff = one - zero;
            if (diffIndex.find(diff) == diffIndex.end()) {
                diffIndex[diff] = i;
            }

            if (one == zero) {
                res = one + zero;
            } else {
                res = max(res, i - diffIndex[diff]);
            }
        }

        return res;
    }
};
