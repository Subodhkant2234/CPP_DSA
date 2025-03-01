//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to add two matrices.
    vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        // code here
        vector<vector<int>>res;    
        int r1 = A.size();
        int c1 = A[0].size();
        int r2 = B.size();
        int c2 = B[0].size();
        
        if(r1 != r2 || c1 != c2)
            return res; 
            
        for(int i = 0; i < r1; i++){
            vector<int>row;
            for(int j = 0; j < c1; j++){
                row.push_back(A[i][j]+B[i][j]);
            }
            res.push_back(row);
            row.clear();
        }
        return res;
    }
};
