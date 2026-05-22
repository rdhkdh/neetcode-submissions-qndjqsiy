class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) {return 1;}
        if(n<0) {return myPow(1/x, -n);}

        double y = myPow(x, n/2);
        double ans = y*y;
        if(n%2==1) {ans = ans*x;}

        return ans;
    }
};
