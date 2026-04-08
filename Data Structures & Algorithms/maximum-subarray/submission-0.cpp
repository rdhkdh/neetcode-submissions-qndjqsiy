class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum = 0;
        int best = INT_MIN;

        int n = a.size();

        for(int i=0;i<n;i++)
        {
            sum = max(sum+a[i], a[i]);
            best = max(best, sum);
        }

        return best;
    }
};
