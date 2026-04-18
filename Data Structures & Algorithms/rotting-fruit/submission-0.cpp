class Solution {
public:
    int bfs(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> time(m, vector<int>(n,-1));
        queue<pair<int,int>> q;
        vector<vector<int>> dirns = {{0,-1}, {0,1}, {1,0}, {-1,0}};

        //push intial rotten fruits
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    time[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            int i = u.first;
            int j = u.second;

            for(int k=0;k<4;k++)
            {
                i = u.first + dirns[k][0];
                j = u.second + dirns[k][1];

                //fresh fruit which has not been visited
                if( (j>=0 && j<n) && 
                    (i>=0 && i<m) &&
                    time[i][j]==-1 && 
                    grid[i][j]==1) 
                {
                    grid[i][j] = 2;
                    time[i][j] = time[u.first][u.second] + 1;
                    q.push({i,j});
                }
            }
        }

        //find max time
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //a fresh orange never got rotten
                if(grid[i][j]==1 && time[i][j]==-1)
                {
                    return -1;
                }
                
                ans = max(ans, time[i][j]);
            }
        }

        return ans;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
