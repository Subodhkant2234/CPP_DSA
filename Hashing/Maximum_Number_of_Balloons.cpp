//Maximum Number of Balloons
#include <iostream>
#include <unordered_map>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int minCount = INT_MAX;
        // ToDo: Write Your Code Here.
        unordered_map<char, int> charCount;
        for(char c : text)
            charCount[c]++;

        minCount = min(minCount, charCount['b']);
        minCount = min(minCount, charCount['a']);
        minCount = min(minCount, charCount['l']/2);
        minCount = min(minCount, charCount['o']/2);
        minCount = min(minCount, charCount['n']);

        return minCount;
    }
};
