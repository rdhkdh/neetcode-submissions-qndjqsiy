class Solution {
public:
    vector<int> color; //0=white, 1=gray, 2=black
    vector<vector<int>> adj;
    vector<bool> present;
    vector<int> res; //topological order

    bool dfs(int v)
    {
        if(color[v]==1) {return false;} //cycle detected
        if(color[v]==2) {return true;}

        color[v] = 1;
        for(auto u: adj[v])
        {
            if(!dfs(u)) {return false;} //cycle detected
        }
        color[v] = 2;
        res.push_back(v);

        return true;
    }


    //returns index at which they differ
    int compare(string a, string b)
    {
        int l = min(a.size(), b.size());
        for(int i=0;i<l;i++)
        {
            if(a[i]!=b[i]) {return i;}
        }

        return -1;
    }

    string foreignDictionary(vector<string>& words) {
        //using 0-25 as codes for a-z
        color.resize(26, 0);
        adj.resize(26);
        present.resize(26, false);

        //set present characters
        for(auto s: words)
        {
            for(auto c: s)
            {
                present[c-'a'] = true;
            }
        }

        //create adj list
        for(int i=0;i<words.size()-1;i++)
        {
            int idx = compare(words[i], words[i+1]);

            //if prefix is longer than second word
            if(idx==-1 && words[i].length()>words[i+1].length())
            {
                return "";
            }

            if(idx!=-1)
            {
                int u = words[i][idx] - 'a';
                int v = words[i+1][idx] - 'a';
                adj[u].push_back(v);
            }
        }

        //topological sort
        for(int i=0;i<26;i++)
        {
            if(present[i] && color[i]==0)
            {
                if(dfs(i)==false) return "";
            }
        }
        reverse(res.begin(), res.end());

        string str;
        for(auto i: res)
        {
            str += char(int('a')+i);
        }
        return str;
    }
};
