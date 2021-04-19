class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        double a = x;
        while (N) {
            if (N & 1) {
                ans *= a;
            }
            N >>= 1;
            a *= a;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};