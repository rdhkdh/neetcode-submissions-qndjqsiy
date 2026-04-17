class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        int offset = 1;

        for(int i=1;i<=n;i++)
        {
            if(i == offset*2) //power of 2
            {
                offset=i; 
                dp[i] = 1; 
                continue;
            }
            dp[i] = 1 + dp[i-offset];
        }

        return dp;
    }
};
