class Solution {
public:

    int search(vector<int>& v, int x) {
        int l=0, r=v.size()-1;

        while(l<=r)
        {
            int mid = (l+r)/2;

            if(v[mid]<x) {l = mid+1;}
            else if(v[mid]>x) {r=mid-1;}
            else if(v[mid]==x) {return mid;}
        }

        return -1;
    }
};
