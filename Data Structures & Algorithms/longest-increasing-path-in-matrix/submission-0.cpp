class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<vector<int>> &matrix, int i, int j)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if(dp[i][j] != 0) //visited
        {
            return dp[i][j];
        }

        dp[i][j] = 1;

        //check all 4 dirns

        //down
        if(i+1<m && matrix[i+1][j]>matrix[i][j])
        {
            dfs(matrix, i+1, j);
            dp[i][j] = max(dp[i][j], 1+dp[i+1][j]);
        } 
        //up
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
        {
            dfs(matrix, i-1, j);
            dp[i][j] = max(dp[i][j], 1+dp[i-1][j]);
        }
        //left
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
        {
            dfs(matrix, i, j-1);
            dp[i][j] = max(dp[i][j], 1+dp[i][j-1]);
        }
        //right
        if(j+1<n && matrix[i][j+1]>matrix[i][j])
        {
            dfs(matrix, i, j+1);
            dp[i][j] = max(dp[i][j], 1+dp[i][j+1]);
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        dp.resize(m, vector<int>(n, 0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==0) //not visited
                {
                    dfs(matrix, i, j);
                }
            }
        }

        int lip = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                lip = max(lip, dp[i][j]);
            }
        }

        return lip;
    }
};
