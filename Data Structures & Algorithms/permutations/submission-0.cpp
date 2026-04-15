class Solution {
public:


    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        if(n==1) 
        {
            res.push_back(nums);
            return res;
        }

        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(auto u: nums)
            {
                if(u!=nums[i]) {v.push_back(u);}
            }

            vector<vector<int>> temp = permute(v);

            for(auto u: temp)
            {
                u.insert(u.begin(), nums[i]);
                res.push_back(u);
            }
        }

        return res;
    }
};
