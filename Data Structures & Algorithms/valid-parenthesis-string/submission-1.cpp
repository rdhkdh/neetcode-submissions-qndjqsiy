class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> s_left, s_star; //indices

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') {s_left.push(i);}
            else if(s[i]=='*') {s_star.push(i);}
            else if(s[i]==')')
            {
                if(!s_left.empty()) {s_left.pop();}
                else{
                    if(!s_star.empty()) {s_star.pop();}
                    else{return false;}
                }
            }
        }

        while(!s_left.empty())
        {
            if(s_star.empty()) {return false;}
            if(s_left.top() > s_star.top()) {return false;}

            s_left.pop(); 
            s_star.pop();
        }

        return true;
    }
};
