/*
Start from the top-right cell(row = 0, col = N – 1) and store the ans = -1. If the value in the current cell is 1, 
update ans with the current row and move left. 
Otherwise, if the current cell is 0, move to the next row:
If mat[row][col] == 1, update ans = row and move left by col = col – 1.
Else if mat[row][col] == 0, row = row + 1.
Continue, till we move outside the grid and return ans.
  */

#include <bits/stdc++.h>
using namespace std;

// The main function that returns index of row with maximum
// number of 1s.
int rowWithMax1s(vector<vector<bool>>& mat) {
    int maxRow = -1, row = 0;
    int R = mat.size();
    int C = mat[0].size();
    int col = C - 1;

    // Move till we are inside the matrix
    while (row < R && col >= 0) {
        // If the current value is 0, move down to the next row
        if (mat[row][col] == 0) {
            row += 1;
        }
        // Else if the current value is 1, update ans and
        // move to the left column
        else {
            maxRow = row;
            col -= 1;
        }
    }
    return maxRow;
}
