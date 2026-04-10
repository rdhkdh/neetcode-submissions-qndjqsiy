class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int i = 0, j = 1;
        int ans = 0;

        if(n==1) {return 0;}

        while(i<j && j<n)
        {
            if(prices[j] >= prices[i])
            {
                ans = max(ans, prices[j]-prices[i]);
                j++;
            }
            else
            {
                i=j;
                j++;
            }
        }

        return ans;
    }
};
