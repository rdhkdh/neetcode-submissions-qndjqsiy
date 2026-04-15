class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i=0; i<(1<<n); i++)
        {
            vector<int> subset;
            for(int j=0;j<n;j++)
            {
                int temp = i & (1<<j);
                if(temp==(1<<j)) 
                {
                    subset.push_back(nums[j]);
                }
            }
            sort(subset.begin(),subset.end());
            s.insert(subset);
        }

        for(auto u: s)
        {
            ans.push_back(u);
        }
        return ans;
    }
};
