#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> combination;
    vector<vector<int>> combinations;
    vector<int> nums;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;

        combinations.push_back({});
        traceback(0, 0, n);

        return combinations;
    }

    void traceback(int cur, int index, int n) {
        if (cur == n) return;

        for (int i = index; i < n; i++) {
            combination.push_back(nums[i]);
            combinations.push_back(combination);
            traceback(cur + 1, i + 1, n);
            combination.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3};
    int target = 8;
    vector<vector<int>> ans = solution.subsets(nums);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}