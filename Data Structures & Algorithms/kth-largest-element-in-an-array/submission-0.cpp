class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; //min heap

        for(auto u: nums)
        {
            if(pq.size()<k) {pq.push(u);}
            else if(pq.size()==k)
            {
                if(u>pq.top()) {pq.push(u);}
                while(pq.size()>k) {pq.pop();}
            }
        }

        if(pq.size()<k) {return 0;}
        return pq.top();
    }
};
