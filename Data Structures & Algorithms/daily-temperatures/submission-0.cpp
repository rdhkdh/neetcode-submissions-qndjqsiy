class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk; //stores indices of the temps
        int n = temp.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && temp[i] > temp[stk.top()])
            {
                ans[stk.top()] = i-stk.top();
                stk.pop();
            }
            
            stk.push(i);
        }

        return ans;
    }
};
