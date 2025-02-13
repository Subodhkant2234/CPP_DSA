//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int largest = arr[0];
        int second_largest = -1;
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > largest){
                second_largest = largest;
                largest = arr[i];
            }
            else if(arr[i] < largest && arr[i] > second_largest){
                    second_largest = arr[i];
            }
        }
        return second_largest;
    }
};
