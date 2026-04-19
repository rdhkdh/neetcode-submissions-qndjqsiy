class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<=1) {return;}

        int top = 0, left = 0;
        int bottom = n-1, right = n-1;
        while(top<bottom && left<right)
        {
            int len = bottom-top+1;
            //-------3 swaps using (top, left) as temp cell-------
            swap(matrix[top][left], matrix[top][right]);
            swap(matrix[top][left], matrix[bottom][right]);
            swap(matrix[top][left], matrix[bottom][left]);

            //-----------3 swaps using top as temp array----------
            //swap right and top
            for(int i=1; i<=len-2; i++)
            {
                swap(matrix[top][left+i], matrix[top+i][right]);
            }
            //swap bottom and top
            for(int i=1; i<=len-2; i++)
            {
                swap(matrix[top][left+i], matrix[bottom][right-i]);
            }
            //swap left and top
            for(int i=1; i<=len-2; i++)
            {
                swap(matrix[top][left+i], matrix[bottom-i][left]);
            }

            top++; bottom--;
            left++; right--;
        }
    }
};
