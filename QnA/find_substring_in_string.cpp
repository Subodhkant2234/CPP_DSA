// C++ program to check if a string is substring of other
// using nested loops

#include <iostream>
using namespace std;

// Function to find if pat is a substring of txt
int findSubstring(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length();

    // Iterate through txt
    for (int i = 0; i <= n - m; i++) {

        // Check for substring match
        int j;
        for (j = 0; j < m; j++) {

            // Mismatch found
            if (txt[i + j] != pat[j]) {
                break;
            }
        }

        // If we completed the inner loop, we found a match
        if (j == m) {

            // Return starting index
            return i;
        }
    }
    
    // No match found
    return -1;
}
