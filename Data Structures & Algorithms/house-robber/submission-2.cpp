class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        //dp[i][0] = not robbing, dp[i][1] = robbing

        dp[0][0] = 0;
        dp[0][1] = 0;

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = a[i-1] + dp[i-1][0];

            ans = max(ans, max(dp[i][0], dp[i][1]));
        }

        return ans;
    }
};
