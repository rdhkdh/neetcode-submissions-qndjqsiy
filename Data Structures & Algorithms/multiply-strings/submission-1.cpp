class Solution {
   public:
    string add(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();

        if (n2 > n1) {
            return add(b, a);
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        int carry = 0;
        for(int i=0; i<n2; i++)
        {
            int r = int(a[i]-'0') + int(b[i]-'0') + carry;
            carry = r/10;
            ans += to_string(r%10);
        }
        for(int i=n2; i<n1; i++)
        {
            int r = int(a[i]-'0') + carry;
            carry = r/10;
            ans += to_string(r%10);
        }
        if(carry!=0)
        {
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply_single(string a, int x) 
    {
        int n = a.length();
        int carry = 0;
        string ans = "";

        for(int i=n-1; i>=0; i--)
        {
            int r = int(a[i]-'0')*x + carry;
            carry = r/10;
            ans += to_string(r%10);
        }
        if(carry!=0)
        {
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if(num2=="0" || num1=="0") {return "0";}

        int n1 = num1.length();
        int n2 = num2.length();
        if(n2>n1) {return multiply(num2, num1);}

        vector<string> v;
        for(int i=n2-1; i>=0; i--)
        {
            int x = num2[i]-'0';
            string t = multiply_single(num1, x);

            //add trailing zeros
            int num_zeros = n2-i-1;
            for(int j=1; j<=num_zeros; j++) {t+="0";}

            v.push_back(t);
        }

        string res = "0";
        for(auto str: v)
        {
            res = add(res, str);
        }
        
        return res;
    }
};
