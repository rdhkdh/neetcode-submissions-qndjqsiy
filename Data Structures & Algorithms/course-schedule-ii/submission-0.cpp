class Solution {
public:
    vector<int> color; //0=white, 1=grey, 2=black
    vector<int> res; //topological sort

    //true for cycle, false for no cycle
    bool dfs(vector<vector<int>> &adj, int v)
    {
        if(color[v]==1) {return true;} //cycle
        if(color[v]==2) {return false;}

        color[v] = 1;
        for(auto u: adj[v])
        {
            if(dfs(adj, u)) return true;
        }
        color[v] = 2;
        res.push_back(v); //add to res when completed

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        color.resize(numCourses, 0);
        
        vector<vector<int>> adj(numCourses);
        for(auto u: prerequisites)
        {
            adj[u[1]].push_back(u[0]);
        }

        for(int i=0; i<numCourses; i++)
        {
            if(color[i]==0)
            {
                if(dfs(adj, i)==true) {return {};}
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
