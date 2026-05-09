//Djikstra's algo
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,int>> visited;
        //min heap
        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            greater<vector<int>>
        > pq; //(max_time_so_far, r, c)

        vector<vector<int>> dirns = {{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({grid[0][0], 0, 0});
        visited.insert({0,0});

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(r==n-1 && c==n-1) {return t;}

            for(auto d: dirns)
            {
                int r1 = r + d[0];
                int c1 = c + d[1];
                if(r1<0 || c1<0 || r1>=n || c1>=n) {continue;}
                if(visited.find({r1,c1})!=visited.end()) {continue;}

                visited.insert({r1,c1});
                pq.push({ max(t,grid[r1][c1]), r1, c1 });
            }
        }

        return -1;
    }
};
