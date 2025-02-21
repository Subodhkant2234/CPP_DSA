class Solution {
public:
    int reverse(int x) {
        int tmp = x;
        int rev = 0;
        int rem = 0;
        if (x == INT_MIN)
            return 0;
        if (x < 0) {
            x = (-1) * x;
        }
        while (x > 0) {
            rem = x % 10;
            x = x / 10;
            if (rev > (INT_MAX / 10))
                return 0;
            rev = rev * 10 + rem;
        }
        if (tmp < 0)
            return (-1) * rev;
        else
            return rev;
    }
};
