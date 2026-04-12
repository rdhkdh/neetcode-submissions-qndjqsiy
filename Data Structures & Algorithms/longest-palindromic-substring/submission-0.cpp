class Solution {
public:
    string check_char(string s, int i)
    {
        int n = s.length();
        string ans = "";

        //check odd palindrome
        int l = i-1;
        int r = i+1;
        while(l>=0 && r<n)
        {
            if(s[l]==s[r]) {l--; r++;}
            else{break;}
        }
        l++; r--;
        if(r-l+1 > ans.length()) {ans = s.substr(l, r-l+1);}

        //check even palindrome
        l = i;
        r = i+1;
        while(l>=0 && r<n)
        {
            if(s[l]==s[r]) {l--; r++;}
            else{break;}
        }
        l++; r--;
        if(r-l+1 > ans.length()) {ans = s.substr(l, r-l+1);}

        return ans;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        for(int i=0;i<n;i++)
        {
            string temp = check_char(s, i);
            if(temp.length() > ans.length()) {ans = temp;}
        }

        return ans;
    }
};
