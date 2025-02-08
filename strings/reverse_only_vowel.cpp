#include <iostream>
#include <string>

class Solution {
  public:
    int isVowel(char c){
      return (c=='a' || c=='A' || c=='e' ||
            c=='E' || c=='i' || c=='I' ||
            c=='o' || c=='O' || c=='u' ||
            c=='U');
    }

    std::string reverseVowels(std::string s) {
      // TODO: Write your code here
      int i = 0;
      int j = s.length()-1 ;

      while(i < j){
        if(!isVowel(s[i])) {
          i++;
          continue;
        }
         if(!isVowel(s[j])) {
          j--;
          continue;
        }
        if(i < j) {
          swap(s[i], s[j]);
          i++;
          j--;
        }

      }
      return s;
    }
};
