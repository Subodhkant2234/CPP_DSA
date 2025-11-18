#include <bits/stdc++.h>
using namespace std;

// Function to reverse the string using recursion
void revStr(string &s, int l, int r) {
  
    // Base case: When left and right pointer meet
    if (l >= r)
        return;

    // Swap characters at left and right
    swap(s[l], s[r]);

    // Recursive call to reverse remaining substring
    revStr(s, l + 1, r - 1);
}

int main() {
    string s = "Hello World";

    // Call the recursive function to reverse string
    revStr(s, 0, s.length() - 1);

    cout << s;
    return 0;
}
