class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1) {return 0;}

        sort(intervals.begin(), intervals.end(), comp);

        int count = 0;
        int i=0, j=1;
        while(j<n)
        {
            if(intervals[j][0] < intervals[i][1]) //overlapping
            {
                count++;

                //retain interval with earlier ending time
                if(intervals[i][1] <= intervals[j][1]) 
                { j++; }
                else
                { 
                    i = j;
                    j++;
                }
            }
            else //non overlapping
            {
                i = j;
                j++;
            }
        }

        return count;
    }
};
