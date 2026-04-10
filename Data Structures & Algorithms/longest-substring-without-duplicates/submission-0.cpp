class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st; //tells whether present or not in O(1)

        int i=0, j=0;
        int ans = 0;
        while(j<n)
        {
            if(st.find(s[j]) == st.end()) //not duplicate
            {
                st.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
            else //duplicate found
            { 
                st.erase(s[i]);
                i++;
            }
        }

        return ans;
    }
};
