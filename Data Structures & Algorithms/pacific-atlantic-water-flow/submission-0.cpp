class Solution {
public:
    vector<vector<bool>> visited;

    void dfs(vector<vector<int>> &heights, int i, int j, bool &pacific, bool &atlantic)
    {
        int m = heights.size();
        int n = heights[0].size();
        if(i<0 || j<0 || i>=m || j>=n) {return;}
        if(visited[i][j]) {return;}
        if(pacific && atlantic) {return;}

        visited[i][j] = true;
        if(i==0 || j==0) {pacific=true;}
        if(i==m-1 || j==n-1) {atlantic=true;}

        vector<vector<int>> dirns = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int k=0;k<4;k++)
        {
            int i1 = i + dirns[k][0];
            int j1 = j + dirns[k][1];

            if(i1>=0 && i1<m && j1>=0 && j1<n &&
                heights[i1][j1] <= heights[i][j])
            {
                dfs(heights, i1, j1, pacific, atlantic);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        visited.resize(m, vector<bool>(n, false));
        bool pacific = false;
        bool atlantic = false;

        vector<vector<int>> res;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(heights, i, j, pacific, atlantic);
                if(pacific && atlantic)
                {
                    res.push_back({i,j});
                }

                pacific = false;
                atlantic = false;
                visited = vector<vector<bool>>(m, vector<bool>(n, false));
            }
        }

        return res;
    }
};
