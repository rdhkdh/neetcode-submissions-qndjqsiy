class Solution {
public:
    //counting palindromes with length > 1
    int check_char(string s, int i)
    {
        int n = s.length();
        int count = 0;

        //check odd palindrome
        int l = i-1;
        int r = i+1;
        while(l>=0 && r<n)
        {
            if(s[l]==s[r]) {l--; r++; count++;}
            else {break;}
        }
        //l++; r--;
        //if(r-l+1 > 1) {count += ((r-l)/2);}

        //check even palindrome
        l = i;
        r = i+1;
        while(l>=0 && r<n)
        {
            if(s[l]==s[r]) {l--; r++; count++;}
            else {break;}
        }
        //l++; r--;
        //if(r-l+1 > 1) {count += ((r-l+1)/2);}

        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        count += n; //all single chars are palindromes

        for(int i=0;i<n;i++)
        {
            count += check_char(s,i);
        }

        return count;
    }
};
