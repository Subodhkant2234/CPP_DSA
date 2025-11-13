#https://takeuforward.org/plus/dsa/problems/reverse-a-number

class Solution {
   public:
    int reverseNumber(int x) {
        int rem, ans = 0;
        while (x) {
            rem = x % 10;  // get last digit
            x = x / 10;    // remove last digit
                           // check for overflow before multiplying by 10
            if (ans > (INT_MAX / 10) || ans < (INT_MIN / 10)) {
                return 0;
            }
            ans = ans * 10 + rem;
        }
        return ans;
    }
};
