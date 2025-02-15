#include <iostream>

class Solution {
public:
  int mySqrt(int x) {
    if (x < 2) return x; // return x if x is less than 2, since the square root of x = 0 or 1 is x itself.

    int left = 2, right = x / 2; 
    int mid;
    long num;
    while (left <= right) { // binary search for the square root.
      mid = left + (right - left) / 2; 
      num = (long) mid * mid;
      if (num > x)
        right = mid - 1; // if mid * mid is greater than x, set right to mid - 1.
      else if (num < x)
        left = mid + 1; // if mid * mid is less than x, set left to mid + 1.
      else
        return mid; // if mid * mid is equal to x, return mid.
    }

    return right;
  }
};

