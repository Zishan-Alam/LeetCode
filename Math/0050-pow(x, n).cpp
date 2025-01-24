class Solution {
public:
    double solve(double x, long n){
        if(x == 0) return 0;
        if(n == 0) return 1;

        if(n < 0) return solve(1/x, -n);

        return (n % 2 == 0) ? solve(x*x, n/2) : x * solve(x*x, n/2);
    }

    double myPow(double x, int n) {
        return solve(x,n);
    }
};
