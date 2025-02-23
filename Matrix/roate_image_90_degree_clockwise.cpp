class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

/*================================================================================
    Another Way to reverse row rather than reverse function 
/*
class Solution {
public:
    void reverse_mat(vector<vector<int>>& matrix, int k, int j){
        int i = 0;
        while(i < j){
            int tmp = matrix[k][i];
            matrix[k][i] = matrix[k][j];
            matrix[k][j] = tmp;
            i++;
            j--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int row = 0; row < n; row++) //reverse row of matrix
          reverse_mat(matrix, row, matrix[row].size()-1);
    }
};

*/
