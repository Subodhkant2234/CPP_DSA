class Solution {
    public:
        string reverseWords(string s) {
            string cur_word = "";
            string result = "";
            vector<string> word;
    
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ') {
                    if (cur_word.size() > 0)
                        word.push_back(cur_word);
                    cur_word = "";
                } else {
                    cur_word += s[i];
                }
            }
            if (cur_word.size() > 0)
                word.push_back(cur_word);
    
            for (int i = word.size() - 1; i >= 0; i--) {
                result += word[i];
                if (i != 0)
                    result += ' ';
            }
            return result;
        }
    };

/* Another method in place, without taking extra memory */
  /*
    int n = s.size();
    string temp = "";
    string ans = "";
    int i = 0;
    while (i < n) {
        temp = "";
        while (s[i] != ' ' && i < n) {
            temp += s[i];
            i++;
        }
        while (s[i] == ' ' && i < n) {
            i++;
        }
        if (!temp.empty()) {
            if (ans.empty())
                ans += temp;
            else
                ans = temp + ' ' + ans;
        }
    }
    return ans;
*/
