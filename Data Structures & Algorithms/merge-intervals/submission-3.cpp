class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> res;
        int n = v.size();
        if(n<=1) {return v;}

        //sort by start times
        sort(v.begin(), v.end(), comp);

        int i=0; 
        int j=1;
        while(j<n)
        {
            if(v[j][0] <= v[i][1]) //overlapping
            {
                v[i][0] = min(v[i][0], v[j][0]);
                v[i][1] = max(v[i][1], v[j][1]);

                j++;
            }
            else //not overlapping
            {
                res.push_back(v[i]);
                i = j;
                j++;
            }
        }
        res.push_back(v[i]);

        return res;
    }
};
