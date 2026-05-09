// bellman ford algo for SSSP
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        //relax all edges for n-1 rounds
        for(int i=1; i<=n-1; i++)
        {
            for(auto x: times)
            {
                int u = x[0];
                int v = x[1];
                int w = x[2];

                if(dist[u]!=INT_MAX)
                {
                    dist[v] = min(dist[v], dist[u]+w);
                }
            }
        }

        //no need to check for -ve cycle since times are +ve

        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans = max(ans, dist[i]);
        }

        if(ans==INT_MAX) {return -1;}

        return ans;
    }
};
