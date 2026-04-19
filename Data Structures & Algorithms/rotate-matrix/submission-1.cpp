class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //reverse the matrix by rows
        reverse(matrix.begin(), matrix.end());

        //transpose the matrix by diagonal
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
