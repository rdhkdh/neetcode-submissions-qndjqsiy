class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(auto u: s)
        {
            if(u=='(' || u=='{' || u=='[')
            {
                stk.push(u);
            }
            else if(u==')')
            {
                if(stk.empty()) {return false;}
                auto c = stk.top();
                if(c != '(') {return false;}
                stk.pop();
            }
            else if(u=='}')
            {
                if(stk.empty()) {return false;}
                auto c = stk.top();
                if(c != '{') {return false;}
                stk.pop();
            }
            else if(u==']')
            {
                if(stk.empty()) {return false;}
                auto c = stk.top();
                if(c != '[') {return false;}
                stk.pop();
            }
        }

        if(!stk.empty()) {return false;}

        return true;
    }
};
