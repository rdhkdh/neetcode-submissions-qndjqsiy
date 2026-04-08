class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size(); 
        int n = B.size();
        int half = (m+n+1) / 2;

        if (B.size() < A.size()) {return findMedianSortedArrays(B, A);}

        int l = 0;
        int r = m;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < m ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < n ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (((m+n)%2) != 0) 
                {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } 
            else if (Aleft > Bright) {r = i - 1;} 
            else {l = i + 1;}
        }
        return -1;
    }
};