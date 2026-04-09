class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) {return 0;}

        //prefix[i] = max height upto i (included)
        //suffix[i] = max height upto i from behind 
        vector<int> prefix(n); 
        vector<int> suffix(n);
        
        prefix[0] = height[0];
        for(int i=1; i<n; i++)
        {
            prefix[i] = max(prefix[i-1], height[i]);
        }

        suffix[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suffix[i] = max(suffix[i+1], height[i]);
        }

        int water_area = 0;
        for(int i=1; i<=n-2; i++)
        {
            water_area += max(0,(min(prefix[i-1], suffix[i+1]) - height[i]));
        }

        return water_area;
    }
};
