class Solution {
  public:
    string encode(string s) {
        // code here
        int count = 0;
        string ans = "";
        for(int i = 1, count = 1; i <= s.length(); i++){
            if(i == s.length() || s[i] != s[i-1]){
                ans += s[i-1] + to_string(count);
                count = 1;
            } else {
                count++;
            }
        }
        return ans;
    }
};
