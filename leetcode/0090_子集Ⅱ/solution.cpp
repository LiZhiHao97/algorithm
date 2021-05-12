#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> combination;
    vector<vector<int>> combinations;
    vector<int> nums;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        this->nums = nums;

        combinations.push_back({});
        traceback(0, 0, n);

        return combinations;
    }

    void traceback(int cur, int index, int n) {
        if (cur == n) return;

        for (int i = index; i < n; i++) {
            if (i == index || (nums[i] != nums[i - 1])) {
                combination.push_back(nums[i]);
                combinations.push_back(combination);
                traceback(cur + 1, i + 1, n);
                combination.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,4,4,1,4};
    int target = 8;
    vector<vector<int>> ans = solution.subsetsWithDup(nums);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}