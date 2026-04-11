class Solution {
public:
    //checking if t's freq map is subset of s substring freq map
    bool isSubset(map<char,int> mp, map<char, int> t_freq_map)
    {
        for(auto u: t_freq_map)
        {
            if(mp.find(u.first) == mp.end()) {return false;}
            else
            {
                if(mp[u.first] < u.second) {return false;}
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        int n = s.length();
        int i = 0;
        map<char,int> mp;
        map<char, int> t_freq_map;
        for(auto c: t) {t_freq_map[c]++;}

        string ans = "";
        for(int j=0;j<n;j++)
        {
            mp[s[j]]++;

            while(isSubset(mp, t_freq_map))
            {
                if(ans=="" || j-i+1 < ans.length())
                {
                    ans = s.substr(i, j-i+1);
                }

                mp[s[i]]--;
                if(mp[s[i]]==0) {mp.erase(s[i]);}
                i++;
            }
        }

        return ans;
    }
};
