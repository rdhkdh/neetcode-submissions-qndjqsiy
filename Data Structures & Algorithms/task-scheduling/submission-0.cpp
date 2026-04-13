class Solution {
public:
    // max heap for available tasks
    // cooldown queue for unavailable tasks

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(auto c: tasks) {count[c-'A']++;}

        priority_queue<int> pq; //max heap: freq
        for(int i=0;i<26;i++)
        {
            if(count[i]>0) {pq.push(count[i]);}
        }

        int time = 0;
        queue<pair<int,int>> q; //(remaining count, next available time)
        while(!pq.empty() || !q.empty())
        {
            time++;

            //if no task available, jump to next available time
            if(pq.empty()) 
            {
                time = q.front().second;
            }
            else //if tasks are available
            {
                int f = pq.top();
                pq.pop();
                f--;

                //if count is still there, send to cooldown
                if(f > 0)
                { 
                    q.push({f, time+n}); 
                }
            }

            //if a task has cooled down
            if(!q.empty() && q.front().second==time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
