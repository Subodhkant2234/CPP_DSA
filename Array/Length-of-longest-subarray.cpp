class Solution {
    /* Function that returns the longest subarray
       of non-negative integers */
  public:
    int longestSubarry(vector<int>& arr) {
        // write code here
        int res = 0;
        int cur = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < 0){
                cur = 0;
            } else {
                cur++;
                res = max(res, cur);
            }
        }
        return res;
    }
};
