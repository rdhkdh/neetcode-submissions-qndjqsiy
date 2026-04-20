class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--)
        {
            //update buying dp
            int skip = dp[i+1][0];
            int buy = dp[i+1][1] - prices[i];
            dp[i][0] = max(skip, buy);

            //update selling dp
            int skip2 = dp[i+1][1];
            int sell = (i+2<n) ? dp[i+2][0] + prices[i] : prices[i];
            dp[i][1] = max(skip2, sell);
        }

        return dp[0][0];
    }
};
