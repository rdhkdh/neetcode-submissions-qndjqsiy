class Solution {
public:
    //vector<vector<bool>> visited;

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n) {return;}

        if(grid[i][j]=='1')
        {
            grid[i][j] = '.'; //mark visited
            //check 4 neighbours
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //visited.resize(m, vector<bool>(n, false));

        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};
