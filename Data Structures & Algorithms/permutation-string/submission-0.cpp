class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> count(26, 0);
        vector<int> s1_freq_map(26, 0);

        // freq map for s1
        for (auto u : s1) {
            s1_freq_map[u - 'a']++;
        }

        int i = 0;

        for (int j = 0; j < n2; j++)
        {
            count[s2[j] - 'a']++;

            if (j - i + 1 > n1) 
            {
                count[s2[i] - 'a']--;
                i++;
            }

            if (j - i + 1 == n1) 
            {
                if (count == s1_freq_map) return true;
            }
        }

        return false;
    }
};