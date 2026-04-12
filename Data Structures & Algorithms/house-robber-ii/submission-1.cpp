class Solution {
public:
    int rob_linear(vector<int> a)
    {
        int n = a.size();
        if(n==0) {return 0;}
        if(n==1) {return a[0];}

        int dp[n+1][2];
        dp[0][0] = 0; //not rob
        dp[0][1] = 0; //rob

        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + a[i-1];
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }

        return ans;
    }

    int rob(vector<int>& a) {
        int n = a.size();
        if(n==0) {return 0;}
        if(n==1) {return a[0];}

        vector<int> p(a.begin(), a.begin()+n-1); //[start,end)
        vector<int> s(a.begin()+1, a.end());

        return max(rob_linear(p), rob_linear(s));

    }
};
