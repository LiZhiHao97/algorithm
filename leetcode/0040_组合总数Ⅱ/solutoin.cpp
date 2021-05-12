#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 回溯 + 剪枝
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> combination;
        vector<vector<int>> combinations;
        sort(candidates.begin(), candidates.end());

        traceback(0, target, candidates, combination, combinations, n);

        return combinations;
    }

    void traceback(int start, int remain, vector<int>& candidates, vector<int>& combination, vector<vector<int>>& combinations, int n) {
        if (remain <= 0) {
            if (remain == 0) {
                combinations.push_back(combination);
            }
            return;
        }

        for (int i = start; i < n; i++) {
            if (i == start || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                traceback(i + 1, remain - candidates[i], candidates, combination, combinations, n);
                combination.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = solution.combinationSum2(candidates, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}