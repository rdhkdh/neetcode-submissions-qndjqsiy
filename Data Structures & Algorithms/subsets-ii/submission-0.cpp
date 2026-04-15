class Solution {
public:
    void solve(vector<int> nums, int i, vector<int> &subset, vector<vector<int>> &res)
    {
        if(i==nums.size())
        {
            res.push_back(subset);
            return;
        }
        
        //include nums[i]
        subset.push_back(nums[i]);
        solve(nums, i+1, subset, res);
        subset.pop_back();

        //excluse nums[i] and skip duplicates
        while(i+1<nums.size() && nums[i]==nums[i+1]) 
        {
            i++;
        }
        solve(nums, i+1, subset, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        solve(nums, 0, subset, res);

        return res;
    }
};
