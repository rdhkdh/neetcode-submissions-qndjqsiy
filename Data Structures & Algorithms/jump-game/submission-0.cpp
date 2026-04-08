class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        vector<bool> v(n, false);

        v[n-1] = true;
        int good_index = n-1;

        for(int i = n-2; i>=0; i--)
        {
            if(i+a[i] >= good_index)
            {
                v[i] = true;
                good_index = i;
            }
        }

        return v[0];
    }
};
