class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int len = s.size();
        int i = 0;
        int sign = 1;

        while (s[i] == ' ')
            i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }

        while (i < len) {
            if (isdigit(s[i])) {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX && sign == -1)
                    return INT_MIN;
                else if (ans > INT_MAX && sign == 1)
                    return INT_MAX;
            } else {
                return ans * sign;
            }
            i++;
        }
        return ans * sign;
    }
};
