class Solution {
public:
    vector<vector<int>> dp;

    void dfs(vector<vector<int>> &matrix, int i, int j)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if(dp[i][j] != 0) //visited
        {
            return;
        }

        dp[i][j] = 1;

        //check all 4 dirns
        vector<vector<int>> dirn = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(int d=0;d<4;d++)
        {
            int i1 = i + dirn[d][0];
            int j1 = j + dirn[d][1];

            if(i1<m && i1>=0 && j1<n && j1>=0 
                && matrix[i1][j1]>matrix[i][j])
            {
                dfs(matrix, i1, j1);
                dp[i][j] = max(dp[i][j], 1+dp[i1][j1]);
            }
        }
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
