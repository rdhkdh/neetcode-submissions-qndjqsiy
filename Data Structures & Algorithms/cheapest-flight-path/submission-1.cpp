//bellman for with only k+1 iterations
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int i=1;i<=k+1;i++)
        {
            vector<int> temp_dist = dist;

            for(auto f: flights)
            {
                int u = f[0];
                int v = f[1];
                int w = f[2];

                if(dist[u]!=INT_MAX && dist[u]+w < temp_dist[v]) 
                {
                    temp_dist[v] = dist[u]+w;
                }
            }

            dist = temp_dist;
        }

        if(dist[dst]==INT_MAX) {return -1;}

        return dist[dst];
    }
};
