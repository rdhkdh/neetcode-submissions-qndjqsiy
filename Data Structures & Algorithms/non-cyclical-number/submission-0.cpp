class Solution {
public:
    int digit_square_sum(string s)
    {
        int sum = 0;
        for(auto u: s)
        {
            int d = u-'0';
            sum += (d*d);
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        unordered_set<int> st;

        while(n!=1)
        {
            //n already encountered before
            if(!st.empty() && st.find(n) != st.end()) 
            {
                return false;
            }

            st.insert(n);

            int sum = digit_square_sum(to_string(n));
            n = sum;
        }

        return true;
    }
};
