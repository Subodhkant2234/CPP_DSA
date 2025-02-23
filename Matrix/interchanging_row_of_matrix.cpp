//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    public:
    //Function to interchange the rows of a matrix.
    void interchangeRows(vector<vector<int> > &matrix)
    {
        // code here 
        
        int n = matrix[0].size();
        
        for(int i = 0; i < n; i++){
            int low = 0;
            int high = matrix.size()-1;
            
            while(low < high){
                swap(matrix[low][i], matrix[high][i]);
                low++;
                high--;
            }
        }
    }
};
