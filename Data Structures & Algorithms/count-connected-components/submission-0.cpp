class Solution {
public:
    vector<bool> visited;

    void dfs(vector<vector<int>> &adj, int v)
    {
        if(visited[v]) {return;}

        visited[v] = true;
        for(auto u: adj[v])
        {
            dfs(adj, u);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        vector<vector<int>> adj(n);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj, i);
                count++;
            }
        }

        return count;
    }
};
