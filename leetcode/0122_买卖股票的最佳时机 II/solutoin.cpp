#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    // 动态规划 状态转移方程dp[i][j]
    // i代表天数，j代表持股状态，0代表持有现金，1代表持有股票
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int> (2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];

    }
    // 贪心算法
    int maxProfit2(vector<int>& prices) {
        int ret = 0;
        int n = prices.size();
        if (n < 2) {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i - 1];

            ret += diff > 0 ? diff : 0;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> prices{7,1,5,3,6,4};

    int ans = solution.maxProfit(prices);

    cout << ans << endl;


    return 0;
}