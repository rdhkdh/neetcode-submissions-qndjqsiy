class Solution {
public:
    vector<int> color; //0=white, 1=grey, 2=black

    //find cycle in graph
    bool dfs(vector<vector<int>> &adj, int v)
    {
        if(color[v]==1) {return true;}
        if(color[v]==2) {return false;}

        color[v] = 1;

        for(auto u: adj[v])
        {
            if(dfs(adj,u)) {return true;}
        }

        color[v] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        color.resize(n, 0);
        vector<vector<int>> adj(n);

        for(auto u: prerequisites)
        {
            adj[u[1]].push_back(u[0]);
        }

        
        for(int i=0;i<n;i++)
        {
            if(color[i]==0 && dfs(adj, i)) //cycle found
            {
                return false;
            }
        }

        return true;
    }
};
