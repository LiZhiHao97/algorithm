#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void traceback(int pos, vector<int>& cur, vector<vector<int>>& res, int n) {
        if (pos == n) {
            res.emplace_back(cur);
            return;
        }
        for (int i = pos; i < n; i++) {
            swap(cur[i], cur[pos]);
            traceback(pos + 1, cur, res, n);
            swap(cur[i], cur[pos]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        traceback(0, nums, res, n);

        return res;
    }
};

int main() {
    Solution solution;
    int a[3] = { 1, 2, 3 };
    vector<int> nums(a, a + 3);
    vector<vector<int>> ans = solution.permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}