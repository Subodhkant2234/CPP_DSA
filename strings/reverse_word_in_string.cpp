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