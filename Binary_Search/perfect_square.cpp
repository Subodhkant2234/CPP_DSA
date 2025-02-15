#include <iostream>

class Solution {
public:
    // Function to check whether a given number is a perfect square
    bool isPerfectSquare(int num) {
        if (num < 2) return num == 1;
        long left = 2, right = num / 2;
        // Loop until left is less than or equal to right
        while (left <= right) {
            long mid = (left + right) / 2;
            long guess = mid * mid;
            // if guess is equal to num, return true
            if (guess == num) return true;
            // if guess is less than num, update left to mid + 1
            if (guess < num) left = mid + 1;
            // else update right to mid - 1
            else right = mid - 1;
        }
        // if no perfect square is found, return false
        return false;
    }
};

