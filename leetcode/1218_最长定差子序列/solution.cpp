#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int ans = 0;
        unordered_map<int, int> dp;

        for (int cur: arr) {
            dp[cur] = dp[cur - difference] + 1;
            ans = max(ans, dp[cur]);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference = -2;

    int ans = solution.longestSubsequence(arr, difference);

    cout << ans << endl;

    return 0;
}