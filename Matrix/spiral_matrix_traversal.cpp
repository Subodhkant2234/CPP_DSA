/*
The problem requires us to traverse a 2D matrix in spiral order. This means we have to move in a pattern
Left to Right (top row)
Top to Bottom (rightmost column)
Right to Left (bottom row, if any)
Bottom to Top (leftmost column, if any)
We repeat these steps while there are still unvisited elements in the matrix

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> v;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++)
                v.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                v.push_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    v.push_back(matrix[bottom][i]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return v;
    }
};
