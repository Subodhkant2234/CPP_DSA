//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void reverse_col(vector<vector<int>> &mat, int row, int col){
        for(int j = 0; j < col; j++){
            int i = 0;
            int k = row-1;
            while(i < k){
                swap(mat[i][j], mat[k][j]);
                k--;
                i++;
            } 
        }
    }
    
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        for(int i = 0; i < mat.size(); i++){
            for(int j = i+1; j < mat[0].size(); j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        int row = mat.size();
        int col = mat[0].size();
        reverse_col(mat, row, col);
    }
};
