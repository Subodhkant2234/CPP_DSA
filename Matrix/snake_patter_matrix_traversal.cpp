//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends



class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>res;     
        int left = 0, right = c;
        for(int i = 0; i < r; i++){   
            if(i%2 == 0){
                for(int j = left; j < right; j++)
                    res.push_back(matrix[i][j]);
            } else {
                for(int k = right-1; k >= left; k--)
                    res.push_back(matrix[i][k]);
            }
        }
        return res;
    }
};
