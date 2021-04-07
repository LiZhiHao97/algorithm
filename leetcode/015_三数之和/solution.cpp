#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int first = 0; first < n; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n - 1; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while(second < third && nums[second] + nums[third] > target) {
                    third--;
                }
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target){
                    ans.push_back({ nums[first], nums[second], nums[third] });
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int a[6] = { -1, 0, 1, 2, -1, -4 };
    vector<int> nums(a, a + 6);
    vector<vector<int>> ans =  solution.threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
