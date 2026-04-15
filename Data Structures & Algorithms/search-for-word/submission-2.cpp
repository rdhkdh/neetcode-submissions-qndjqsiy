class Solution {
public:
    bool check_range(vector<vector<char>> board, int r, int c)
    {
        int m = board.size();
        int n = board[0].size();
        if(r<0 || r>=m) {return false;}
        if(c<0 || c>=n) {return false;}

        return true;
    }

    bool dfs(vector<vector<char>> &board, int r, int c, string word, int i)
    {
        if(i==word.length()) {return true;}
        if(!check_range(board, r, c)) {return false;}

        if(board[r][c]==word[i])
        {
            char temp = board[r][c];
            board[r][c] = '.'; //mark visited

            bool ans = 
            dfs(board, r, c-1, word, i+1) ||
            dfs(board, r, c+1, word, i+1) ||
            dfs(board, r-1, c, word, i+1) ||
            dfs(board, r+1, c, word, i+1);

            board[r][c] = temp;

            return ans;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
