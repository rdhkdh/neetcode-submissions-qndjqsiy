class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1; //k_min
        int r = *max_element(piles.begin(), piles.end()); //k_max

        int ans = r;
        while(l<=r)
        {
            int k = (l+r)/2;

            //check correctness
            int h0 = 0;
            for(int i=0;i<n;i++)
            {
                h0 += ((piles[i]+k-1)/k); //ceil(piles[i]/k)
            }

            if(h0<=h) 
            {
                ans = min(ans, k);
                r = k-1;
            }
            else 
            {
                l = k+1;
            }
        }

        return ans;
    }
};
