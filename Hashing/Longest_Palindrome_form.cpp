#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {        
        int length = 0;
        int found_odd = false;
        // ToDo: Write Your Code Here.
        unordered_map<char, int>mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        for(auto x : mp) {
            if(x.second %2 == 0)
                length = length + x.second;
            else{
                length += (x.second) -1;
                found_odd = true;
            }
        }
        if(found_odd)
            length++;
        return length;
    }
};

