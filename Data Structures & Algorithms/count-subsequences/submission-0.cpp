//dp[i][j] = no of ways to form 1st j characters of t, 
// using 1st i characters of s
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=0;i<=m;i++) {dp[i][0]=1;}

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //not matching
                if(s[i-1] != t[j-1])
                {
                    //skip
                    dp[i][j] = dp[i-1][j];
                }
                else if(s[i-1]==t[j-1]) //matching
                {
                    //skip or not skip
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }

        return dp[m][n];
    }
};
