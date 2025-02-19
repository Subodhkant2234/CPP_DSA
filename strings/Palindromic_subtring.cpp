#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes
            count += expandFromCenter(s, i, i);
            // Check for even length palindromes
            count += expandFromCenter(s, i, i + 1);
        }
        return count;
    }

private:
    int expandFromCenter(string s, int left, int right) {
        int count = 0;
        // Check for palindrome while staying within string boundaries
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};

