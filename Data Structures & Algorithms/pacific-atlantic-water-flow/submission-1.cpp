class Solution {
public:
    vector<vector<bool>> visited;

    void dfs(vector<vector<int>> &heights, int i, int j)
    {
        int m = heights.size();
        int n = heights[0].size();
        if(i<0 || j<0 || i>=m || j>=n) {return;}
        if(visited[i][j]) {return;}

        visited[i][j] = true;

        vector<vector<int>> dirns = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int k=0;k<4;k++)
        {
            int i1 = i + dirns[k][0];
            int j1 = j + dirns[k][1];

            if(i1>=0 && i1<m && j1>=0 && j1<n &&
                heights[i1][j1] >= heights[i][j])
            {
                dfs(heights, i1, j1);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        visited.resize(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        //check pacific border cells
        for(int i=0;i<m;i++)
        {
            dfs(heights, i, 0);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights, 0, j);
        }

        //mark the visited cells in answer
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j])
                {
                    ans[i][j]++;
                }
            }
        }

        visited = vector<vector<bool>>(m, vector<bool>(n,false));
        vector<vector<int>> res;

        //check atlantic border cells
        for(int i=0;i<m;i++)
        {
            dfs(heights, i, n-1);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights, m-1, j);
        }

        //mark the visited cells in answer
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j])
                {
                    ans[i][j]++;
                    if(ans[i][j]==2) 
                    {
                        res.push_back({i,j});
                    }
                }
            }
        }

        return res;
    }
};
