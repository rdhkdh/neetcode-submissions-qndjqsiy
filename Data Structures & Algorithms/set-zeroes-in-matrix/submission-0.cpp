class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //using top row and left col as bool arrays

        int m = matrix.size();
        int n = matrix[0].size();

        int top_row = 1; //1=no zeros found, 0=zeros found
        int left_col = 1;
        
        //check col 0
        for(int r=0;r<m;r++)
        {
            if(matrix[r][0]==0)
            {
                left_col = 0;
                break;
            }
        }

        //check row 0
        for(int c=0; c<n; c++)
        {
            if(matrix[0][c]==0)
            {
                top_row = 0;
                break;
            }
        }

        //check cols
        for(int c=1;c<n;c++)
        {
            for(int r=0;r<m;r++)
            {
                if(matrix[r][c]==0)
                {
                    matrix[0][c] = 0;
                    break;
                }
            }
        }

        //check rows
        for(int r=1;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                if(matrix[r][c]==0)
                {
                    matrix[r][0] = 0;
                    break;
                }
            }
        }

        //set all 0s
        //cols 1 to n-1        
        for(int c=1;c<n;c++)
        {
            if(matrix[0][c]==0)
            {
                for(int r=1;r<m;r++)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        //rows 1 to m-1
        for(int r=1;r<m;r++)
        {
            if(matrix[r][0]==0)
            {
                for(int c=1;c<n;c++)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        //row 0
        if(top_row==0)
        {
            for(int c=0;c<n;c++)
            {
                matrix[0][c]=0;
            }
        }

        //col 0
        if(left_col==0)
        {
            for(int r=0;r<m;r++)
            {
                matrix[r][0]=0;
            }
        }

    }
};
