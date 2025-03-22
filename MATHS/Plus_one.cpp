class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        int l = 0;
        int r = digits.size()-1;

        while( l <= r) {
            if(digits[r] == 9){
                digits[r] = 0;
                r--;
                continue;
            } else {
                digits[r] = digits[r]+1;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
