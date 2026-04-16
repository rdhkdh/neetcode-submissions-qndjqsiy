class Solution {
public:
    void solve(string s, int i, vector<string> &v, vector<vector<string>> &res)
    {
        if(i==s.length())
        {
            res.push_back(v);
            return;
        }

        for(int j=i;j<s.length();j++)
        {
            string t = s.substr(i, j-i+1);
            string t1 = t;
            reverse(t1.begin(), t1.end());
            if(t == t1) 
            {
                v.push_back(t);
                solve(s, j+1, v, res);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;

        solve(s, 0, v, res);

        return res;
    }
};
