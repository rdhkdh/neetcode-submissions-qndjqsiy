class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        vector<vector<int>> res;
        int n = v.size();
        if(n<=1) {return v;}

        //already sorted by start times

        int i=0;
        int j=1;
        while(j<n)
        {
            if(v[j][0] <= v[i][1]) //overlapping
            {
                v[i][0] = min(v[i][0], v[j][0]);
                v[i][1] = max(v[i][1], v[j][1]);

                j++;
            }
            else //not overlapping
            {
                res.push_back(v[i]);
                i = j;
                j++;
            }
        }
        res.push_back(v[i]);

        return res;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        int n = intervals.size();
        if(n==0) 
        {
            v.push_back(newInterval); 
            return v;
        }

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
        return merge(v);
    }
};
