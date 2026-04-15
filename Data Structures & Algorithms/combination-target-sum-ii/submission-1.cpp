class Solution {
public:
    void solve(vector<int> a, int target, int i, vector<int> &v, vector<vector<int>> &res)
    {
        if(target==0) 
        {
            res.push_back(v);
            return;
        }
        if(i==a.size()) {return;}

        //include a[i]
        if(target-a[i]>=0)
        {
            v.push_back(a[i]);
            solve(a, target-a[i], i+1, v, res);
            v.pop_back();
        }

        //exclude a[i]
        int j=i+1;
        for(j=i+1; j<a.size(); j++) //skip duplicates
        {
            if(a[j]!=a[j-1]) {break;}
        }
        solve(a, target, j, v, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> res;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, v, res);

        return res;
    }
};
