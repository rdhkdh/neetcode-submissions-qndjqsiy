class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        int n = intervals.size();
        if(n==0) {v.push_back(newInterval); return v;}

        //insert interval at right place in sorted array
        int i=0;
        for(i=0; i<n; i++)
        {
            if(intervals[i][0] < newInterval[0])
            {
                v.push_back(intervals[i]);
            }
            if(intervals[i][0] >= newInterval[0])
            {
                break;
            }
        }
        v.push_back(newInterval);
        for(int j = i; j<n; j++)
        {
            v.push_back(intervals[j]);
        }

        //merge intervals
        vector<vector<int>> res;
        n = v.size();
        int j=0; //i is already pointing at newly inserted interval
        int k=1;
        while(k<n)
        {
            if(v[k][0] <= v[j][1]) //overlapping
            {
                v[j][0] = min(v[j][0], v[k][0]);
                v[j][1] = max(v[j][1], v[k][1]);

                k++;
            }
            else //not overlapping
            {
                res.push_back(v[j]);
                j = k;
                k++;
            }
        }
        res.push_back(v[j]);

        return res;
    }
};
