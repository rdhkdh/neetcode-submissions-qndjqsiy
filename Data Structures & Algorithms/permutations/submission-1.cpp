class Solution {
public:
    void solve(vector<int> nums, vector<bool> &visited, vector<int> &perm, vector<vector<int>> &res)
    {
        if(perm.size() == nums.size()) 
        {
            res.push_back(perm); 
            return;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(!visited[i])
            {
                //include nums[i]
                perm.push_back(nums[i]);
                visited[i] = true;
                solve(nums, visited, perm, res);
                perm.pop_back();

                //exclude nums[i]
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> perm;
        vector<vector<int>> res;
        solve(nums, visited, perm, res);

        return res;
    }  
};
