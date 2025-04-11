class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "";
    
            for (int i = 0; i < strs[0].size(); i++) {
                for (int j = 1; j < strs.size(); j++) {
                    if (strs[j][i] != strs[0][i])
                        return ans;
                }
                ans = ans + strs[0][i];
            }
            return ans;
        }
    };
/*
      string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
*/
