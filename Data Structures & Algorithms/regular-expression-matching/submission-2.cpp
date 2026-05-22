class Solution {
   public:
    vector<vector<int>> dp;

    bool dfs(string s, string p, int i, int j) {
        int m = s.length();
        int n = p.length();
        if (j == n) {
            return (i == m);
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (i < m && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < n && p[j + 1] == '*') {
            // option 1: skip p[j] and *
            // option 2: use 1 char of p[j] and keep at j

            dp[i][j] = dfs(s, p, i, j+2) || (match && dfs(s, p, i + 1, j));
        } 
        else {
            dp[i][j] = match && dfs(s, p, i+1, j+1);
        }

        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return dfs(s, p, 0, 0);
    }
};
