#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();

        if (n + m != k) {
            return false;
        }

        auto dp = vector<vector<int>> (n + 1, vector<int> (m + 1));

        dp[0][0] = 1;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution solution;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

    bool ans = solution.isInterleave(s1, s2, s3);

    cout << ans << endl;

    return 0;
}