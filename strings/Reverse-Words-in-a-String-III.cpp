class Solution {
public:
    string reverseWords(string s) {
        string result = "", word;        // Initialize an empty result string and word string
        for (char ch : s) { // Iterate over each character in the input string
            if (ch != ' ') // If the character is not a space, it is part of a word
                word += ch; // Append the character to the word string
            else { // If the character is a space, it indicates the end of a
    
                reverse(word.begin(), word.end()); // Reverse the word
                result += word + " "; // Append the reversed word to the result
                                      // string with a space
                word = "";            // Reset the word string for the next word
            }
        }
        reverse(word.begin(), word.end()); // Reverse the last word
        result += word; // Append the reversed last word to the result string
        return result;  // Return the final reversed sentence
    }
};
