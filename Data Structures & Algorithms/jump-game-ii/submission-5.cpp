class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();

        int l=0, r=0;
        int jumps = 0;

        while(r<n-1)
        {
            int max_index = 0;
            for(int i=l; i<=r; i++)
            {
                max_index = max(max_index, i+a[i]);
            }

            l = r+1;
            r = max_index;
            jumps++;
        }
        
        return jumps;
    }
};
