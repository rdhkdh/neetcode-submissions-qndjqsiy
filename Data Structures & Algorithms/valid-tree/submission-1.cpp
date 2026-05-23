class Solution {
public:
    vector<int> color;

    //true = cycle present, false = acyclic
    bool dfs(vector<vector<int>> &adj, int v)
    {
        if(color[v]==1) {return true;}
        if(color[v]==2) {return false;}

        color[v] = 1;
        for(auto u: adj[v])
        {
            if(color[u]==0 && dfs(adj, u))
            {
                return true;
            }
        }
        color[v] = 2;

        return false;
    }

    
    bool validTree(int n, vector<vector<int>>& edges) {
        //tree = n-1 edges and acyclic
        if(edges.size() != n-1) {return false;}
       
        //check for cycle
        color.resize(n, 0);
        vector<vector<int>> adj(n);
        for(auto u: edges)
        {
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        
        bool ans = !dfs(adj, 0);

        //check if unvisited nodes are still there
        for(int i=0;i<n;i++)
        {
            if(color[i]==0) 
            {
                return false; //disconnected component
            }
        }
        
        return ans;
    }
};
