#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace  std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0, temp = 0;
        while (x != 0) {
            temp = x % 10;
            x /= 10;

            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && temp > 7)) return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && temp < -8)) return 0;

            ans = ans * 10 + temp;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int x = -123;
    int ans =  solution.reverse(x);
    cout << ans << endl;
    return 0;
}
