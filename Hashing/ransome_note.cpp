#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create an unordered_map to store character frequencies from the magazine
        unordered_map<char, int> charCount;
        
        // Populate the unordered_map with character frequencies from the magazine
        for (char c : magazine) {
            charCount[c]++;
        }
        
        // Check if the ransom note can be constructed
        for (char c : ransomNote) {
            if (charCount[c] == 0) {
                return false;
            }
            charCount[c]--;
        }
        
        return true;
    }
};

