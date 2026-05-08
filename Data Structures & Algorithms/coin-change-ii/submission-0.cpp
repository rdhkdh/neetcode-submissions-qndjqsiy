class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int k = coins.size();

        vector<vector<int>> dp(k+1, vector<int>(amount+1, 0));
        for(int i=0;i<=k;i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                //not take coin
                dp[i][j] = dp[i-1][j];

                //take coin
                if(j-coins[i-1] >= 0)
                {
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }

        return dp[k][amount];
    }
};
