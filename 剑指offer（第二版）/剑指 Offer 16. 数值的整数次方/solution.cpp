class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long b = n;
        if (b < 0) {
            b = -b;
            x = 1 / x;
        }

        while (b) {
            if (b & 1) {
                ans *= x;
            }
            b = b >> 1;
            x *= x;
        }

        return ans;
    }
};