#include <bits/stdc++.h>
using namespace std;

// Function to sort a stack in ascending order
class Solution {
    public:
    stack<int> sortStack(stack<int> &input) {
        // Create a temporary stack to store sorted elements
        stack<int> tmpStack;
        
        // Iterate through the input stack until it's empty
        while (!input.empty()) {
            // Pop the top element from the input stack
            int tmp = input.top();
            input.pop();
            
            // Compare the popped element with elements in the temporary stack
            // Move elements from temporary stack to input stack until the right position is found
            while (!tmpStack.empty() && tmpStack.top() > tmp) {
                input.push(tmpStack.top()); // Move elements back to input stack
                tmpStack.pop();
            }
            
            // Place the popped element in the correct position in the temporary stack
            tmpStack.push(tmp);
        }
        
        // Return the sorted temporary stack
        return tmpStack;
    }
};

