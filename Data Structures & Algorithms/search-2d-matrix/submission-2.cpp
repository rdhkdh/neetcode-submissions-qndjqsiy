class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //find which row
        int top = 0, bottom = m-1;

        while(top<=bottom)
        {
            int mid = (top+bottom)/2;

            if(target<matrix[mid][0]) {bottom = mid-1;}
            else if(matrix[mid][n-1]<target) {top = mid+1;}
            else{break;}
        }

        if(top>bottom) {return false;}
        int row = (top+bottom)/2;

        //search within row
        int l=0, r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(matrix[row][mid]>target) {r=mid-1;}
            else if(matrix[row][mid]<target) {l=mid+1;}
            else{return true;}
        }

        return false;
    }
};
