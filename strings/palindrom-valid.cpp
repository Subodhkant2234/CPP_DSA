//https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/valid-palindrome-easy

class Solution {
public:
  bool isPalindrome(std::string s) {
    int i = 0, j = s.length() - 1; // initialize two pointers, one at the start and one at the end of the string
    while (i < j) { // continue until the two pointers cross over
      while (i < j && !isalnum(s[i])) { // move i forward until a letter or digit is found
        i++;
      }
      while (i < j && !isalnum(s[j])) { // move j backward until a letter or digit is found
        j--;
      }
      
      // compare the characters at i and j after converting them to lowercase
      if (tolower(s[i]) != tolower(s[j])) 
        return false; // if they are not equal, the string is not a palindrome
      i++; // move i forward
      j--; // move j backwards
    }
    
    return true; // if the two pointers have crossed over, the string is a palindrome
  }
};
