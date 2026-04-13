class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //(distsq, index): max heap acc to distsq
        priority_queue<pair<int,int>> pq; 
        int n = points.size();

        for(int i=0;i<n;i++)
        {
            int distsq = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            if(pq.size()<k)
            {
                pq.push({distsq, i});
            }
            else if(pq.size()==k)
            {
                if(distsq < pq.top().first)
                {
                    pq.push({distsq, i});
                }
                while(pq.size()>k) {pq.pop();}
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};
