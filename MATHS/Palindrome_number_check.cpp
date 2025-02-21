class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0;
        int tmp = x;
        int digit = 0;
        if (x == 0)
            return true;
        if (x < 0 || x % 10 == 0)
            return false;

        while (tmp) {
            digit = tmp % 10;
            tmp = tmp / 10;
            rev = rev * 10 + digit;
        }
        return rev == x;
    }
};
