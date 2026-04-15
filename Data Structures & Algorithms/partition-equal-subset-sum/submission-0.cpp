class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(auto u: nums) {sum += u;}
        if(sum%2==1) {return false;}
        int t = sum/2;

        bool dp[n+1][t+1];
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = false;
        }
        for(int j=0;j<t+1;j++)
        {
            dp[0][j] = false;
        }
        dp[0][0] = true;

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<t+1;j++)
            {
                if(j-nums[i-1] >= 0)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                } 
            }
        }

        return dp[n][t];
    }
};
