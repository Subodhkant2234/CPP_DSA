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


/*
class Solution {
public:
   string expandAroundCenter(const string &s, int left, int right) {
    int n = s.size();
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return the substring from (left+1) to right - 1
    return s.substr(left + 1, right - left - 1);
    }

string longestPalindrome(string s) {
    if (s.empty()) return "";
    string longest = "";
    int n = s.length();
    for (int i = 0; i < n; i++) {
        // Check for odd length palindromes
        string odd = expandAroundCenter(s, i, i);
        
        // Check for even length palindromes
        string even = expandAroundCenter(s, i, i + 1);
        
        // Update longest palindrome
        if (odd.length() > longest.length()) {
            longest = odd;
        }
        if (even.length() > longest.length()) {
            longest = even;
        }
    }
    return longest;
    }
};

*/
