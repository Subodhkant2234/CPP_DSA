class Solution {
  public:
    string encode(string s) {
        // code here
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            int count = 1;
            while(i < n-1 && s[i] == s[i+1]){
                count++;
                i++;
            }
            ans += s[i];
            ans += to_string(count);
        }
        return ans;
    }
};
