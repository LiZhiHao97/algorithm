#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return max(1, n - 1);
        }

        vector<int> dp(n + 1, 0);

        int ans = 0;

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                ans = max(ans, dp[i - j] * dp[j]);
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 10;
    int ans = solution.cuttingRope(n);

    cout << ans << endl;
}