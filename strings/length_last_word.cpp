//58. Length of Last Word
class Solution {
    public:
        int lengthOfLastWord(string s) {
            int len = s.length();
            int i = len - 1;
            int length = 0;
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            while (i >= 0 && s[i] != ' ') {
                length++;
                i--;
            }
            return length;
        }
    };
