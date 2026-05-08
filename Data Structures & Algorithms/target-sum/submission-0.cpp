class Solution {
public:
    map<pair<int,int>, int> dp; //(index, target): no of ways

    int solve(vector<int> &nums, int i, int target)
    {
        int n = nums.size();
        if(i>=n)
        {
            if(target==0) {return 1;}
            else {return 0;}
        }

        dp[{i+1, target+nums[i]}] = solve(nums, i+1, target+nums[i]);
        dp[{i+1, target-nums[i]}] = solve(nums, i+1, target-nums[i]);

        return dp[{i+1, target+nums[i]}] + dp[{i+1, target-nums[i]}];
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};
