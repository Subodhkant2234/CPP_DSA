class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int l = 0, r = 0;
            int count = 0, res = 0;
            int arr[256] = {0};
            int len = s.length();
    
            while (r < len) {
                arr[s[r]]++;
                while (arr[s[r]] > 1) {
                    arr[s[l]]--;
                    l++;
                }
                count = r-l+1;
                res = max(res, count);
                r++;
            }
            return res;
        }
    };