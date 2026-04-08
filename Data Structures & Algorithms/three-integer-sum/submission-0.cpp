class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());

        set<vector<int>> s;
        for(int i=0;i<n;i++)
        {
            int target = -a[i];
            int l=0, r=n-1;
            while(l<r)
            {
                int sum = a[l]+a[r];

                if(sum==target)
                {
                    if(l!=i && r!=i)
                    {
                        vector<int> v = {a[i], a[l], a[r]};
                        sort(v.begin(), v.end());
                        s.insert(v);
                    }
                    l++; r--;
                }
                else if(sum<target)
                {
                    l++;
                }
                else if(sum>target)
                {
                    r--;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto u: s)
        {
            ans.push_back(u);
        }

        return ans;
    }
};
