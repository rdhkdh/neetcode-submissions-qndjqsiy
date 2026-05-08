class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums(n+2, 0);
        new_nums[0] = 1;
        new_nums[n+1] = 1;
        for(int i=1;i<=n;i++) {new_nums[i] = nums[i-1];}

        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        for(int l=n;l>=1;l--)
        {
            for(int r=l;r<=n;r++)
            {
                for(int i=l;i<=r;i++)
                {
                    int coins = new_nums[l-1] 
                                * new_nums[i]
                                * new_nums[r+1];

                    coins += (dp[l][i-1] + dp[i+1][r]);

                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return dp[1][n];
    }
};
