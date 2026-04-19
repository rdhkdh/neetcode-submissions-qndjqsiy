/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(Interval &a, Interval &b)
    {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);


        for(int i=0;i<n-1;i++)
        {
            if(intervals[i].end > intervals[i+1].start)
            {
                return false;
            }
        }

        return true;
    }
};
