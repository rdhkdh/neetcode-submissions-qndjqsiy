class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        int max_a=0, max_b=0, max_c=0;
        for(int i=0;i<n;i++)
        {
            if(triplets[i][0]>target[0] 
            || triplets[i][1]>target[1] 
            || triplets[i][2]>target[2])
            {
                continue;
            }
            else
            {
                max_a = max(max_a, triplets[i][0]);
                max_b = max(max_b, triplets[i][1]);
                max_c = max(max_c, triplets[i][2]);
            }
        }

        if(max_a==target[0] 
        && max_b==target[1] 
        && max_c==target[2])
        {
            return true;
        }
        return false;
    }
};
