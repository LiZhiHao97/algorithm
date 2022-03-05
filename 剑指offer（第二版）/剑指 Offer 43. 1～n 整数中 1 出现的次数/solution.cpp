class Solution {
public:
    int countDigitOne(int n) {
        int cur = n % 10;
        long long digit = 1;
        int high = n / 10;
        int low = 0;
        int res = 0;

        while (high != 0 || cur != 0) {
            if (cur == 0) res += high * digit;
            else if (cur == 1) res += high * digit + low + 1;
            else res += (high + 1) * digit;
            
            low += cur * digit;
            cur = high % 10;
            digit *= 10;
            high = high / 10;
        }

        return res;
    }
};