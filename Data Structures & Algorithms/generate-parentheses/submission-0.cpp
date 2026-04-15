class Solution {
public:
    void solve(int n, int open, int close, string t, vector<string> &res)
    {
        if(open+close == (2*n))
        {
            if(open==close) {res.push_back(t);}
            return;
        }

        // add ')'
        if(open>close)
        {
            t += ')';
            solve(n, open, close+1, t, res);
            t.pop_back();
        }

        // add '('
        t += '(';
        solve(n, open+1, close, t, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string t = "";

        solve(n, 0, 0, t, res);

        return res;
    }
};
