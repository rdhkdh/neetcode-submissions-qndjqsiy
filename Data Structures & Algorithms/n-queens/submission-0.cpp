class Solution {
public:
    bool check(vector<string> board, int r, int c)
    {
        int n = board.size();

        //check column
        for(int i=0;i<r;i++)
        {
            if(board[i][c]=='Q') {return false;}
        }

        //check upper left diagonal
        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j]=='Q') {return false;}
        }

        //check upper right diagonal
        for(int i=r-1, j=c+1; i>=0 && j<n; i--, j++)
        {
            if(board[i][j]=='Q') {return false;}
        }

        return true;
    }

    void solve(vector<string> &board, int r, vector<vector<string>> &res)
    {
        int n = board.size();
        if(r==n)
        {
            res.push_back(board);
            return;
        }

        //include rth queen
        for(int c=0;c<n;c++)
        {
            if(check(board, r, c))
            {
                board[r][c] = 'Q';
                solve(board, r+1, res);
                board[r][c] = '.'; //restore to original state
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string row;
        vector<string> board;
        for(int i=1;i<=n;i++) {row += '.';}
        for(int i=1;i<=n;i++) {board.push_back(row);}

        solve(board, 0, res);

        return res;
    }
};
