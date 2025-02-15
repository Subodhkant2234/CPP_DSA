#include <iostream>
#include <vector>

class Solution {
public:
  // Function to generate an array of squares of elements in a sorted order.
  std::vector<int> makeSquares(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> squares(n); // Create a vector to store the squares.
    int highestSquareIdx = n - 1; // Initialize the index for the highest square.
    int left = 0, right = n - 1; // Initialize two pointers, one from the left and one from the right.

    // Iterate until the left and right pointers meet or cross.
    while (left <= right) {
      int leftSquare = arr[left] * arr[left]; // Calculate the square of the element at the left pointer.
      int rightSquare = arr[right] * arr[right]; // Calculate the square of the element at the right pointer.

      // Compare the squares of elements at left and right pointers.
      if (leftSquare > rightSquare) {
        squares[highestSquareIdx--] = leftSquare; // Store the larger square at the highest available index.
        left++; // Move the left pointer to the right.
      } else {
        squares[highestSquareIdx--] = rightSquare; // Store the larger square at the highest available index.
        right--; // Move the right pointer to the left.
      }
    }
    return squares; // Return the sorted array of squares.
  }
};

