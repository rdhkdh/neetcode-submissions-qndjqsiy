class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int,int>> mp;
        int n = s.length();

        vector<bool> inString(26, false);
        for(int i=0;i<n;i++)
        {
            int alph = int(s[i])-int('a');

            if(!inString[alph]) //first occurence
            {
                mp[s[i]] = {i, i}; //{start,end}
                inString[alph] = true;
            }
            else //not first occurence
            {
                mp[s[i]].second = i; //update end index
            }
        }

        vector<pair<int,int>> v;
        for(auto u: mp)
        {
            v.push_back(u.second);
        }
        sort(v.begin(), v.end());

        //merge overlapping intervals
        vector<int> ans; //sizes of the merged intervals
        int curr_start = v[0].first;
        int curr_end = v[0].second;

        for(int i=1; i<v.size(); i++)
        {
            if(v[i].first <= curr_end)
            {
                curr_end = max(curr_end, v[i].second);
            }
            else
            {
                ans.push_back(curr_end-curr_start+1);
                curr_start = v[i].first;
                curr_end = v[i].second;
            }
        }
        ans.push_back(curr_end-curr_start+1);

        return ans;
        
    }
};
