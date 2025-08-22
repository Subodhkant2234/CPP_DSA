These expressions define segments by their start index and length:

s.substr(start, length) extracts a substring from s, starting at start with given length.

s.substr(start) extracts from start to the end (used for the last part).

So this effectively breaks the string into four pieces:

0 to i-1 → s1

i to j-1 → s2

j to k-1 → s3

k to end → s4

====================================================================================================================================
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(const string &s) {
    if (s.empty() || s.size() > 3) return false;
    if (s[0] == '0' && s.size() > 1) return false; // No leading zeros
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

vector<string> generateIpBruteForce(string s) {
    vector<string> res;
    int n = s.size();

    // Try all combinations of 3 dots in the string
    for (int i = 1; i < min(n, 4); i++) {
        for (int j = i + 1; j < min(n, i + 4); j++) {
            for (int k = j + 1; k < min(n, j + 4); k++) {
                if (k >= n) continue;

                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i);
                string s3 = s.substr(j, k - j);
                string s4 = s.substr(k);

                if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                    res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }
    }

    return res;
}

int main() {
    string s = "255678166";
    vector<string> res = generateIpBruteForce(s);

    for (const string &ip : res) {
        cout << ip << endl;
    }

    return 0;
}
