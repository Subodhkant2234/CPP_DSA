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


//2nd method

#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    // List of vowels
    std::string vowels = "aeiouAEIOU";
  
    std::string reverseVowels(std::string s) {
      int first = 0, last = s.length() - 1;
      
      // Convert string to a character array
      std::vector<char> array(s.begin(), s.end());
      
      while (first < last) {
        // Increment first until a vowel is found
        while (first < last && vowels.find(array[first]) == std::string::npos) {
          first++;
        }
        // Decrement last until a vowel is found
        while (first < last && vowels.find(array[last]) == std::string::npos) {
          last--;
        }
        // Swap elements at first and last if they are both vowels
        std::swap(array[first++], array[last--]);
      }
      
      // Convert character array back to string
      return std::string(array.begin(), array.end());
    }
};



