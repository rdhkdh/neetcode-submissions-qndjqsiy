class Solution {
public:
    bool check_col(vector<vector<char>>& board, int c)
    {
        vector<int> v(10, 0);
        for(int i=0;i<9;i++)
        {
            if(board[i][c]!='.') 
            {
                int num = board[i][c] - '0';
                v[num]++;

                if(v[num]>1) {return false;}
            }
        }

        return true;
    }

    bool check_row(vector<vector<char>>& board, int r)
    {
        vector<int> v(10, 0);
        for(int i=0;i<9;i++)
        {
            if(board[r][i]!='.') 
            {
                int num = board[r][i] - '0';
                v[num]++;

                if(v[num]>1) {return false;}
            }
        }

        return true;
    }

    bool check_square(vector<vector<char>>& board, int r, int c)
    {
        vector<int> v(10, 0);
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                if(board[i][j]!='.') 
                {
                    int num = board[i][j] - '0';
                    v[num]++;

                    if(v[num]>1) {return false;}
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            if(!check_col(board, i)) {return false;}
            if(!check_row(board, i)) {return false;}
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                if(!check_square(board, i, j)) {return false;}
            }
        }

        return true;
    }
};
