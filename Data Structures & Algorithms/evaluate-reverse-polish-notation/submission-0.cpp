class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;

        for(auto u: tokens)
        {
            if(u=="+")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                
                s.push(to_string(a+b));
            }
            else if(u=="-")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                
                s.push(to_string(b-a));
            }
            else if(u=="*")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                
                s.push(to_string(a*b));
            }
            else if(u=="/")
            {
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                
                s.push(to_string(b/a));
            }
            else //number
            {
                s.push(u);
            }
        }

        return stoi(s.top());
    }
};
