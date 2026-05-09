class Solution {
public:
    unordered_map<char, vector<char>> adj;
    unordered_map<char, int> color; // 0=white, 1=gray, 2=black
    string ans;

    bool dfs(char u)
    {
        if(color[u] == 1) {return false;} // cycle
        if(color[u] == 2) {return true;} // fully processed

        color[u] = 1;
        for(char v: adj[u])
        {
            if(!dfs(v)) {return false;}
        }
        color[u] = 2;
        ans += u;

        return true;
    }

    string foreignDictionary(vector<string>& words) {

        // collect all chars
        for(auto &w : words)
        {
            for(char c : w) {adj[c];}
        }

        // build graph
        for(int i=0;i<words.size()-1;i++)
        {
            string a = words[i];
            string b = words[i+1];
            int len = min(a.size(), b.size());

            int j = 0;
            while(j<len && a[j]==b[j]) {j++;}

            // invalid prefix case
            if(j==len && a.size()>b.size())
            {return "";}

            if(j<len)
            {
                adj[a[j]].push_back(b[j]);
            }
        }

        // topo sort
        for(auto &[c, _] : adj)
        {
            if(color[c]==0)
            {
                if(!dfs(c)) return "";
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};