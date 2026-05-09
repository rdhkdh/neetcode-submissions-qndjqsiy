// Kruskal's algo for MST construction
// O(n^2 logn)
class Solution {
   public:
    vector<int> link;
    vector<int> size;

    // find representative of x
    int find(int x) {
        while (x != link[x]) {
            x = link[x];
        }

        return x;
    }

    // unite 2 sets with diff reps
    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        // let a be the larger set
        if (size[a] < size[b]) {
            swap(a, b);
        }

        size[a] += size[b];
        link[b] = a;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        link.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) {
            link[i] = i;
        }

        vector<vector<int>> edges;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int ans = 0;
        for(auto u: edges)
        {
            int i = u[1];
            int j = u[2];

            i = find(i);
            j = find(j);
            if(i!=j) 
            {
                unite(i,j);
                ans += u[0]; //dist
            }
        }

        return ans;
    }
};
