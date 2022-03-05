class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long long start = 1, count = 9;

        while (n > count) {
            n -= count;
            start *= 10;
            digit += 1;
            count = 9 * start * digit;
        }
        long long num = start + (n - 1) / digit;
        return int(to_string(num)[(n - 1) % digit] - '0');
    }
};