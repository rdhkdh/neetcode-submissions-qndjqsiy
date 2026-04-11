class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        vector<int> possible_starts;

        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
            if(s.find(nums[i]-1) == s.end()) //can start the sequence
            {
                possible_starts.push_back(nums[i]);
            }
        }

        int ans = 0;
        for(auto u: possible_starts)
        {
            int start = u;
            while(s.find(start) != s.end())
            {
                start++;
            }
            ans = max(start-u, ans);
        }

        return ans;
    }
};
