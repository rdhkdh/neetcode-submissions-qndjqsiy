class Solution {
public:
    vector<char> encoding(char d)
    {
        switch(d){
            case '2': return {'a','b','c'};
            case '3': return {'d','e','f'};
            case '4': return {'g','h','i'};
            case '5': return {'j','k','l'};
            case '6': return {'m','n','o'};
            case '7': return {'p','q','r','s'};
            case '8': return {'t','u','v'};
            case '9': return {'w','x','y','z'};
        }

        return {};
    }

    void solve(string digits, int i, string &code, vector<string> &res)
    {
        if(i==digits.size())
        {
            res.push_back(code);
            return;
        }

        vector<char> v = encoding(digits[i]);
        for(auto c: v)
        {
            code += c;
            solve(digits, i+1, code, res);
            code.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) {return {};}

        vector<string> res;
        string code = "";

        solve(digits, 0, code, res);

        return res;
    }
};
