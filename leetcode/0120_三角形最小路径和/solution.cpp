#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1));
        dp[0][1] = 0;
        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1) {
                    dp[i][j] = dp[i - 1][j] + triangle[i - 1][j - 1];
                    continue;
                }
                if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i - 1][j - 1];
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[n][i]);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    int ans = solution.minimumTotal(triangle);

    cout << ans << endl;

    return 0;
}