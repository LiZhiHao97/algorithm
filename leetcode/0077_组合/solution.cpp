#include <iostream>
#include <vector>

using namespace std;

// 回溯 + 剪枝
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;

        traceback(1, combination, combinations, n, k);

        return combinations;
    }

    void traceback(int start, vector<int>& combination, vector<vector<int>>& combinations, int n, int k) {
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }

        for (int i = start; i <= n - (k - combination.size()) + 1; i++) {
            combination.push_back(i);
            traceback(i + 1, combination, combinations, n, k);
            combination.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int n = 4, k = 2;

    vector<vector<int>> ans = solution.combine(n, k);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}