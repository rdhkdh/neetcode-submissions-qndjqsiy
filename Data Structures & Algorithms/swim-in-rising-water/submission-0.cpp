// binary search + dfs
class Solution {
public:
    //if water level is t, can I reach the bottom right?
    bool dfs(vector<vector<int>> &grid, 
        vector<vector<bool>> & visited,
        int r, int c, int t
    )
    {
        int n = grid.size();

        if(
            r<0 || c<0 || r>=n || c>=n
            || visited[r][c] 
            || t < grid[r][c] 
        ) {return false;}
        if(r==n-1 && c==n-1) {return true;}

        visited[r][c] = true;
        return dfs(grid, visited, r+1, c, t) ||
               dfs(grid, visited, r-1, c, t) ||
               dfs(grid, visited, r, c+1, t) ||
               dfs(grid, visited, r, c-1, t);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        //find min and mx t for binary search
        int max_t = grid[0][0];
        int min_t = grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                max_t = max(max_t, grid[i][j]);
                min_t = min(min_t, grid[i][j]);
            }
        }

        int l = min_t;
        int r = max_t;
        while(l<r)
        {
            int mid = (l+r)/2;

            if(dfs(grid, visited, 0, 0, mid)) {r = mid;}
            else {l = mid+1;}

            //reset the visited grid
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    visited[i][j] = false;
                }
            }
        }

        return r;
    }
};
