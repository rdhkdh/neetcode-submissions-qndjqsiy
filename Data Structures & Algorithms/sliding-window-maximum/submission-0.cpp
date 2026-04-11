class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return {};
        priority_queue<pair<int,int>> pq;
        vector<int> res;

        for(int i=0;i<k-1;i++) {pq.push({nums[i], i});}

        for(int i=0; i<=n-k; i++)
        {
            int end = i+k-1;
            pq.push({nums[end], end});
            
            while(pq.top().second < i) {pq.pop();}

            res.push_back(pq.top().first);
        }

        return res;
    }
};
