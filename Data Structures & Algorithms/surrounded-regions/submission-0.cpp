class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        if(i<0 || j<0 || i>=m || j>=n) {return;}
        if(board[i][j]!='O') {return;}

        board[i][j] = 'T'; //mark unsurrounded O cells
        
        vector<vector<int>> dirns = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            int i1 = i + dirns[k][0];
            int j1 = j + dirns[k][1];

            dfs(board, i1, j1);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') {dfs(board, i, 0);}
            if(board[i][n-1]=='O') {dfs(board, i, n-1);}
        }
        for(int j=1;j<=n-2;j++)
        {
            if(board[0][j]=='O') {dfs(board, 0, j);}
            if(board[m-1][j]=='O') {dfs(board, m-1, j);}
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O') {board[i][j]='X';}
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='T') {board[i][j]='O';}
            }
        }
    }
};
