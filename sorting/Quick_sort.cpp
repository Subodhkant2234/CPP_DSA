//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low >= high)
            return;
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot = arr[high];
        int index = low;
        for(int i = low; i < high; i++){
            if(arr[i] < pivot){
                swap(arr[index], arr[i]);
                index++;
            }
        }
        swap(arr[index], arr[high]);
        return index;
    }
};

//{ Driver Code Starts.
