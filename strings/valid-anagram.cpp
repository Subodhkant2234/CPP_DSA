#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
      // TODO: Write your code here
      unordered_map<char, int> mp;
      if(s.length() != t.length())
        return false;
      
      for(int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
        mp[t[i]]--;
      }
      for(auto var : mp){
        if(var.second != 0)
          return false;
      }
      return true;
    }
};