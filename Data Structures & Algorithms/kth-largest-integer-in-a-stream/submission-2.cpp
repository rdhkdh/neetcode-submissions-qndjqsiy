class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; //min heap
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(auto u: nums)
        {
            if(  pq.size()<k || 
                (pq.size()==k && u>pq.top())
            ) 
            {
                pq.push(u);
            }
            while(pq.size()>k) {pq.pop();}
        }
    }
    
    int add(int val) {

        if(  pq.size()<k || 
            (pq.size()==k && val>pq.top())
        ) 
        {
            pq.push(val);
        }
        while(pq.size()>k) {pq.pop();}

        return pq.top();
    }
};
