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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start_times;
        vector<int> end_times;

        for(auto u: intervals)
        {
            start_times.push_back(u.start);
            end_times.push_back(u.end);
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int i=0, j=0;
        int n = intervals.size();
        int count = 0;
        int max_rooms = 0;
        while(i<n && j<n)
        {
            if(end_times[j] > start_times[i])
            {
                count++;
                i++;
            }
            else if(end_times[j] < start_times[i])
            {
                count--;
                j++;
            }
            else if(end_times[j] == start_times[i])
            {
                i++; j++;
            }

            max_rooms = max(max_rooms, count);
        }

        return max_rooms;
    }
};
