class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }

        sort(v.rbegin(), v.rend()); // sort descending by position

        stack<double> stk;

        for(int i = 0; i < n; i++) {
            double time = (double)(target - v[i].first) / v[i].second;

            if(stk.empty() || time > stk.top()) {
                stk.push(time);
            }
        }

        return stk.size();
    }
};