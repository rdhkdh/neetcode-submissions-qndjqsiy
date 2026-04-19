class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0]<b[0];
    }

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m = queries.size();
        int n = intervals.size();
        vector<int> sorted_queries = queries;
        sort(intervals.begin(), intervals.end(), comp);
        sort(sorted_queries.begin(), sorted_queries.end()); 

        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>> 
        > pq; //min heap of pairs: {size, end time}

        map<int,int> mp; //query val, min size
        int i=0;
        for(auto q: sorted_queries)
        {
            //push intervals which start before q
            while(i<n && q>=intervals[i][0])
            {
                int s = intervals[i][0];
                int e = intervals[i][1];
                pq.push({e-s+1, e});
                i++;
            }

            //remove intervals which end before q
            while(!pq.empty() && pq.top().second < q)
            {
                pq.pop();
            }

            if(pq.empty()) {mp[q] = -1;}
            else{ mp[q] = pq.top().first; }
        }

        vector<int> res;
        for(auto q: queries) {res.push_back(mp[q]); }
        return res;
    }
};
