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

int main() {
  Solution solution;

  std::string s1 = "hello";
  std::string expected_output1 = "holle";
  std::string actual_output1 = solution.reverseVowels(s1);
  std::cout << "Test Case 1: " << (expected_output1 == actual_output1) << std::endl;

  std::string s2 = "DesignGUrus";
  std::string expected_output2 = "DusUgnGires";
  std::string actual_output2 = solution.reverseVowels(s2);
  std::cout << "Test Case 2: " << (expected_output2 == actual_output2) << std::endl;

  std::string s3 = "AEIOU";
  std::string expected_output3 = "UOIEA";
  std::string actual_output3 = solution.reverseVowels(s3);
  std::cout << "Test Case 3: " << (expected_output3 == actual_output3) << std::endl;

  std::string s4 = "aA";
  std::string expected_output4 = "Aa";
  std::string actual_output4 = solution.reverseVowels(s4);
  std::cout << "Test Case 4: " << (expected_output4 == actual_output4) << std::endl;

  std::string s5 = "";
  std::string expected_output5 = "";
  std::string actual_output5 = solution.reverseVowels(s5);
  std::cout << "Test Case 5: " << (expected_output5 == actual_output5) << std::endl;

  return 0;
}

