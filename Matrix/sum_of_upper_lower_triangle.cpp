class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.  
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int upper = 0; 
        int lower = 0; 
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //diagonal elements will be common in both upper and lower sum.
                if(i == j)
                {
                    upper += matrix[i][j];
                    lower += matrix[i][j];
                }
                
                //else if j>i, this condition satisfies only for upper triangle.
                else if (j>i) 
                    upper += matrix[i][j]; 

                //else if i>j, this condition satisfies only for lower triangle.
                else if(j<i)
                    lower += matrix[i][j]; 
            }
        }
        
        //storing both the sum in a list and returning the list.
        vector<int> result;
        result.push_back(upper);
        result.push_back(lower);
        return result; 
    }
};
