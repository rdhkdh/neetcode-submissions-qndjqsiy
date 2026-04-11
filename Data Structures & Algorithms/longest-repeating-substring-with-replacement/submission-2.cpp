class Solution {
public:
    int max_freq(unordered_map<char, int> &mp) {
        int max_f = 0;
        for (auto &u : mp) {
            max_f = max(max_f, u.second);
        }
        return max_f;
    }

    int characterReplacement(string s, int k) {
        int i = 0;
        unordered_map<char, int> mp;
        int ans = 0;

        for (int j = 0; j < s.length(); j++) {
            mp[s[j]]++;

            // shrink until valid
            while ((j - i + 1) - max_freq(mp) > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};