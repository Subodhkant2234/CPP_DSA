class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        int mx = 0;
        int start = 0;
        if (s.size() == 0)
            return "";
        for (int i = 0; i < s.length(); i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < s.length()) {
                if (s[l] != s[r])
                    break;
                if (r - l + 1 > mx) {
                    mx = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length()) {
                if (s[l] != s[r])
                    break;
                if (r - l + 1 > mx) {
                    mx = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        string ans;
        ans = s.substr(start, mx);
        return ans;
    }
};
