class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {
    }
    
    void addNum(int num) {

        if(minheap.empty() || maxheap.empty())
        {
            minheap.push(num);
        }
        else
        {
            if(num<minheap.top())
            {
                maxheap.push(num);
            }
            if(num>=minheap.top())
            {
                minheap.push(num);
            }
        }
        
        //correct the size
        int n1 = maxheap.size();
        int n2 = minheap.size();
        int n = n1+n2;

        if(n2 == n1+2)
        {
            int temp = minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }
        if(n1 == n2+1) //always keeping the later half bigger
        {
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
        //don't need to do anything incase of n2=n1+1, or n2==n1
    }
    
    double findMedian() {
        int n = maxheap.size() + minheap.size();
        if(n==0) {return 0;}

        if(n%2==0)
        {
            int x = maxheap.top();
            int y = minheap.top();

            return double(x+y)/double(2);
        }
        
        //if n is odd
        return double(minheap.top());
    }
};
