class Solution {
public:
    bool isAlphanumeric(char c)
    {
        if(int(c)>=int('a') && int(c)<=int('z'))
        {
            return true;
        }
        else if(int(c)>=int('A') && int(c)<=int('Z'))
        {
            return true;
        }
        else if(int(c)>=int('0') && int(c)<=int('9'))
        {
            return true;
        }

        return false;
    }

    bool check(char a, char b)
    {
        if(a==b) {return true;} //numbers or characters

        //case insensitive
        if( int(a)>=int('a') && int(a)<=int('z') && 
            int(b)>=int('A') && int(b)<=int('Z') )
        {
            if(abs(int(a)-int(b)) == 32) {return true;}
            else{return false;}
        }
        //case insensitive
        if( int(b)>=int('a') && int(b)<=int('z') && 
            int(a)>=int('A') && int(a)<=int('Z') )
        {
            if(abs(int(a)-int(b)) == 32) {return true;}
            else{return false;}
        }

        return false;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int l=0, r=n-1;

        while(l<r)
        {
            if(!isAlphanumeric(s[l])) {l++; continue;}
            if(!isAlphanumeric(s[r])) {r--; continue;}

            if(check(s[l], s[r])) 
            {
                l++; r--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
