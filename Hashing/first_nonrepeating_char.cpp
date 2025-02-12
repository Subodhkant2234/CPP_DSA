#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // Create a hashmap to store the frequency of each character
        unordered_map<char, int> freq;
        
        // Traverse the string to populate the hashmap with character frequencies
        for (char c : s) {
            freq[c]++;
        }
        
        // Traverse the string again to find the first unique character
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        
        // If no unique character is found, return -1
        return -1;
    }
};