#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet;
        vector<int> dp(n + 1, 0);
        for (auto v: wordDict) {
            wordSet.insert(v);
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    string s = "aaaaaaa";
    vector<string> worDict{"aaaa", "aaa"};
    bool ans = solution.wordBreak(s, worDict);

    cout << ans << endl;

    return 0;
}