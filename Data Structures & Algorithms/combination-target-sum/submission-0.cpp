class Solution {
public:
    void sum(vector<int> a, int target, int i, vector<int> &v, vector<vector<int>> &res)
    {
        if(target==0) {res.push_back(v); return;}
        if(i==a.size()) {return;} 
        
        //include a[i]
        if(target-a[i]>=0)
        {
            v.push_back(a[i]);
            sum(a, target-a[i], i, v, res);
            v.pop_back(); //return v to original state
        }

        //exclude a[i]
        sum(a, target, i+1, v, res);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> v;

        sum(nums, target, 0, v, res);
        return res;
    }
};
