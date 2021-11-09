#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<string>> ans;
    vector<string> group;
    int n;
public:
    void dfs(string s, int i) {
        if (i == n) {
            ans.push_back(group);
            return;
        }

        for (int j = i; j < n; j++) {
            if (dp[i][j]) {
                group.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                group.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.assign(n, vector<int> (n, true));

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }

        dfs(s, 0);

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aab";

    vector<vector<string>> ans = solution.partition(s);

    for (auto v: ans) {
        for (auto k: v) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}