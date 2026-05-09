class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = (1+digits[n-1])/10;
        vector<int> res;
        res.push_back((1+digits[n-1]) %10);

        for(int i=n-2; i>=0; i--)
        {
            res.push_back((carry+digits[i])%10);
            carry = (carry+digits[i])/10;
        }
        if(carry!=0)
        {
            res.push_back(carry);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
