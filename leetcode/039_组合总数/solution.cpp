#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> combinations;
        vector<int> combination;

        for (int i = 0; i < n; i++) {
            combination.push_back(candidates[i]);
            traceback(i, target - candidates[i], combinations, combination, candidates, target, n);
            combination.pop_back();
        }

        return combinations;
    }

    void traceback(int index, int res, vector<vector<int>>& combinations, vector<int>& combination, const vector<int>& candidates, const int& target, const int& n) {
        if (res <= 0) {
            if (res == 0) {
                combinations.push_back(combination);
            }
            return;
        }
        for (int i = index; i < n; i++) {
            combination.push_back(candidates[i]);
            traceback(i, res - candidates[i], combinations, combination, candidates, target, n);
            combination.pop_back();
        }
    }
};
int main() {
    Solution solution;
    int a[3] = { 2, 3, 5 };
    int target = 8;
    vector<int> candidate(a, a + 3);
    vector<vector<int>> ans = solution.combinationSum(candidate, target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}