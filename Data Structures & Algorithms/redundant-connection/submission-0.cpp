class Solution {
public:
    vector<int> link;
    vector<int> size;

    int find(int x)
    {
        while(x != link[x])
        {
            x = link[x];
        }

        return x;
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(size[b] > size[a]) {return unite(b,a);}

        size[a] += size[b];
        link[b] = a;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        size.resize(n,1);
        link.resize(n);
        for(int i=0;i<n;i++) {link[i]=i;}

        //reverse(edges.begin(), edges.end());

        vector<vector<int>> ans;
        for(auto e: edges)
        {
            int a = find(e[0]-1);
            int b = find(e[1]-1);

            if(a==b) {ans.push_back(e);}

            unite(e[0]-1, e[1]-1);
        }

        return *ans.rbegin();
    }
};
