class Solution {
public:
    int update_index(int ans, int amid, int mid, int index)
    {
        if(ans<amid) {return mid;}
        return index;
    }

    int binary_search(vector<int> a, int l, int r, int x)
    {
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(a[mid]>x) {r=mid-1;}
            if(a[mid]<x) {l=mid+1;}
            if(a[mid]==x) {return mid;}
        }

        return -1;
    }

    int search(vector<int>& a, int x) {
        int n = a.size();
        int l = 0;
        int r = n-1;

        // binary search to find starting index (min elem) of array
        //int ans = INT_MAX;
        int index = 0; //index of min elem so far
        while(l<=r)
        {
            int mid = (l+r)/2;

            if(a[mid]<a[r]) 
            {
                if(a[mid]<a[index]) {index = mid;}
                //ans = min(ans, a[mid]);
                //index = update_index(ans, a[mid], mid, index);
                r = mid-1;
            }
            else if(a[mid]>a[r]) 
            {
                if(a[mid]<a[index]) {index = mid;}
                //ans = min(ans, a[mid]);
                //index = update_index(ans, a[mid], mid, index);
                l = mid+1;
            }
            else if(a[mid]==a[r]) 
            {
                if(a[mid]<a[index]) {index = mid;}
                // ans = min(ans, a[mid]);
                // index = update_index(ans, a[mid], mid, index);
                break;
            }
        }

        l = 0;
        r = n-1;
        if(x<=a[r]) 
        {
            //binary search btw index - r
            return binary_search(a, index, r, x);
        }
        else
        {
            //binary search btw l - (index-1)
            return binary_search(a, l, index-1, x);
        }

        return -1;
    }
};
