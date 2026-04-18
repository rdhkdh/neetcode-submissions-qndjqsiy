class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return 0;
        }

        if(grid[i][j] == 1)
        {
            grid[i][j] = -1; //mark visited

            //check all 4 neighbours
            return 1 +
                    dfs(grid, i+1, j) +
                    dfs(grid, i-1, j) +
                    dfs(grid, i, j+1) +
                    dfs(grid, i, j-1);
        }

        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }

        return max_area;
    }
};
