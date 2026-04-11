class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for(auto u: strs)
        {
            ans += to_string(u.length());
            ans += '#';
            ans += u;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int curr_len = 0; //length of decoded string
        string temp = "";
        for(auto u: s)
        {
            if(curr_len==0 && u != '#')
            {
                temp += u;
            }
            else if(curr_len==0 && u=='#')
            {
                curr_len = stoi(temp);
                temp = "";

                //handle empty string
                if(curr_len==0) {res.push_back("");}
            }
            else if(curr_len!=0)
            {
                temp += u;
                curr_len--;

                if(curr_len==0) 
                {
                    res.push_back(temp);
                    temp = "";
                }
            }
        }

        return res;
    }
};
