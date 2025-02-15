#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    // Function to find the Next Greater Element (NGE) for each element in the input array.
    std::vector<int> nextLargerElement(std::vector<int> arr) {
        int n = arr.size();
        std::stack<int> s; // Create a stack to store indices of elements.
        std::vector<int> res(n); // Create a vector to store the NGE for each element.

        // Traverse the input array in reverse order.
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack that are less than or equal to the current element.
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }

            // If the stack is empty, there is no greater element to the right, so store -1.
            // Otherwise, the top of the stack contains the NGE for the current element.
            res[i] = s.empty() ? -1 : s.top();

            // Push the current element's index onto the stack for future comparisons.
            s.push(arr[i]);
        }

        return res; // Return the vector containing NGE for each element.
    }
};

