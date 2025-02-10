#include <iostream>
#include <unordered_set>
#include <cctype>
using namespace std;

class Solution {
public:
    // Function to check if given sentence is pangram
    bool checkIfPangram(string sentence) {
        // Create a set to store unique characters
        unordered_set<char> seen;

        // Iterate over each character using a normal for loop
        for (int i = 0; i < sentence.length(); i++) {
            // Convert the current character to lowercase
            char currChar = tolower(sentence[i]);
            
            if (isalpha(currChar)) {
                // Add the character to the set
                seen.insert(currChar);
            }
        }

        // Return true if set size is 26 (total number of alphabets)
        return seen.size() == 26;
    }
};
