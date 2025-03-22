class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int res = 0;
        int row = 0;
        vector<int> vec;
        for (int i = 0; i < r; i++) {
            int count = 0;
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1)
                    count++;
            }
            if (count > res) {
                res = count;
                row = i;
            }
        }
        vec.push_back(row);
        vec.push_back(res);
        return vec;
    }
};
