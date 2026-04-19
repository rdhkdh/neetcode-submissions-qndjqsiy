class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& v) {
        //sort by start times
        sort(v.begin(), v.end(), comp);

        vector<vector<int>> res;
        int n = v.size();
        int j=0; //i is already pointing at newly inserted interval
        int k=1;
        while(k<n)
        {
            if(v[k][0] <= v[j][1]) //overlapping
            {
                v[j][0] = min(v[j][0], v[k][0]);
                v[j][1] = max(v[j][1], v[k][1]);

                k++;
            }
            else //not overlapping
            {
                res.push_back(v[j]);
                j = k;
                k++;
            }
        }
        res.push_back(v[j]);

        return res;
    }
};
