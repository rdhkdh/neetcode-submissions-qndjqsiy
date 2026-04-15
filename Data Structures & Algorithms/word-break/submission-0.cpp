class Solution {
public:
    unordered_map<int, bool> memo;

    bool check(string s, int i, vector<string> words)
    {
        if(memo.find(i) != memo.end()) {return memo[i];}

        for(auto w: words)
        {
            if(i+w.length() <= s.length() && 
            s.substr(i, w.length()) == w)
            {
                if(check(s, i+w.length(), words))
                {
                    memo[i] = true;
                    return true;
                }
            }
        }

        memo[i] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        memo[n] = true;

        return check(s, 0, wordDict);
    }
};
