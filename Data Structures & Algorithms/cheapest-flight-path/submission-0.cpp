//dijkstra's algo
//O(V+ElogE)
//steps = no of edges
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) { 
        //create adj list
        vector<vector<pair<int,int>>> adj(n);
        for(auto v: flights)
        {
            int a = v[0];
            int b = v[1];
            int w = v[2];
            adj[a].push_back({b,w});
        }

        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            greater<vector<int>>
        > pq; //min heap: (cost, node, steps) 
        pq.push({0, src, 0});

        //create dist array: dist[node][steps]
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty())
        {
            int cost = pq.top()[0];
            int a = pq.top()[1];
            int steps = pq.top()[2];
            pq.pop();

            if(a==dst) {return cost;}

            if(steps==k+1) {continue;}
            
            for(auto u: adj[a])
            {
                int b = u.first;
                int w = u.second;

                if(cost+w < dist[b][steps+1])
                {
                    dist[b][steps+1] = cost+w;
                    pq.push({dist[b][steps+1], b, steps+1});
                }
            }
        }

        return -1;
    }
};
