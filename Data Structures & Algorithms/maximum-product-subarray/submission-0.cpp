class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int min_prod = 1;
        int max_prod = 1;
        int best = a[0];

        for(int i=0;i<n;i++)
        {
            int temp = min_prod;
            min_prod = min(a[i], min(min_prod*a[i], max_prod*a[i]));
            max_prod = max(a[i], max(temp*a[i], max_prod*a[i]));

            best = max(best, max_prod);
        }

        return best;
    }
};
