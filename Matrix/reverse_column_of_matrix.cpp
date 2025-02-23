#https://www.geeksforgeeks.org/batch/dsa-4/track/DSASP-Matrix/problem/reversing-the-rows-of-a-matrix-1587115621
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public:
    //Function to reverse the columns of a matrix.
    void reverseCol(vector<vector<int> > &matrix)
    {
        // code here
        int row = matrix.size();
        for(int i = 0; i < row; i++){
            int low = 0;
            int high = matrix[0].size()-1;
            
            while(low < high){
                swap(matrix[i][low], matrix[i][high]);
                low++;
                high--;
            }
        }
    }
};
