class Solution {
   public:
    int longestNonRepeatingSubstring(string& s) {
        int windowStart = 0;
        unordered_map<char, int> mp;
        int maxLen = 0;

        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            char right = s[windowEnd];
            if (mp.find(right) != mp.end() && mp[right] >= windowStart) {
                windowStart = mp[right] + 1;
            }

            mp[right] = windowEnd;

            maxLen = max(maxLen, windowEnd - windowStart + 1);
        }
        return maxLen;
    }
};
