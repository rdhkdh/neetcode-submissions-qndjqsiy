class Solution {
public:
    //checks if they differ in exactly 1 char
    bool check(string a, string b)
    {
        int n = a.length();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i]) {count++;}
        }

        if(count!=1) {return false;}

        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        //endWord must exist
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }
        
        int n = wordList.size();
        vector<vector<int>> adj(n);
        //use indices from wordList as node numbers for the strings
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(wordList[i], wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        //perform BFS to find min no of words in transfn seq
        queue<int> q;
        vector<int> dist(n, INT_MAX);

        //connect beginWord manually
        for(int i=0;i<n;i++)
        {
            if(check(beginWord, wordList[i]))
            {
                dist[i] = 2;
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            if(wordList[v] == endWord) {return dist[v];}

            for(auto u: adj[v])
            {
                if(dist[u]==INT_MAX)
                {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }

        return 0;
    }
};
