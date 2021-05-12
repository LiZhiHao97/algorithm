#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace  std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;

        int revNum = 0;
        while (x > revNum) {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }

        return x == revNum || x == revNum / 10;
    }
};

int main() {
    Solution solution;
    int x = -1213121;
    int ans =  solution.isPalindrome(x);
    cout << ans << endl;
    return 0;
}
