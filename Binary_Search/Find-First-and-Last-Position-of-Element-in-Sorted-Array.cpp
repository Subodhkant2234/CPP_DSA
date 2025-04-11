class Solution {
public:
    int first_occ(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;
        while (low <= high) {
            int mid = (low + (high - low) / 2);
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return first;
    }
    int last_occ(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int second = -1;
        while (low <= high) {
            int mid = (low + (high - low) / 2);
            if (nums[mid] == target) {
                second = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return second;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int first = first_occ(nums, target);
        int last = last_occ(nums, target);
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};
