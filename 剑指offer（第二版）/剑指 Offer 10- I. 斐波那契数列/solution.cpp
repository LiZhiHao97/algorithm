class Solution {
public:
    int fib(int n) {
        int MOD = 1000000007;
        int tmp = 0, pre = 0, next = 1;
        if (n == 0) {
            return pre;
        }
        if (n == 1) {
            return next;
        }

        for (int i = 2; i <= n; i++) {
            tmp = next;
            next = (pre + next) % MOD;
            pre = tmp;
        }
        return next;
    }
};