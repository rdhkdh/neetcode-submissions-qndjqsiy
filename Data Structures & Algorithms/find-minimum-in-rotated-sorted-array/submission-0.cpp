class Solution {
public:
    int findMin(vector<int> &a) {
        int l = 0;
        int r = a.size()-1;

        int ans = INT_MAX;
        while(l<=r)
        {
            int mid = (l+r)/2;

            if(a[mid]<a[r]) 
            {
                ans = min(ans, a[mid]);
                r=mid-1;
            }
            else if(a[mid]>a[r]) 
            {
                ans = min(ans, a[mid]);
                l=mid+1;
            }
            else if(a[mid]==a[r]) 
            {
                ans = min(ans, a[mid]);
                break;
            }
        }

        return ans;
    }
};
