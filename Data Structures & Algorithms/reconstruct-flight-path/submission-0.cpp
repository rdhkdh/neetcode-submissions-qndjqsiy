//Hierholzer's algorithm for Eulerian Path
class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> ans;

    void dfs(string u)
    {
        while(!adj[u].empty())
        {
            string v = *adj[u].begin();
            adj[u].erase(adj[u].begin());

            dfs(v);
        }

        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t: tickets)
        {
            adj[t[0]].insert(t[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
