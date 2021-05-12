#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
            for (int second = first + 1; second < n; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (second < third && nums[second] + nums[third] > target) {
                    third--;
                }
                if (second == third) break;
                if (nums[second] + nums[third] == target) {
                    ans.push_back({ nums[first], nums[second], nums[third] });
                }
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int first = 0; first < n - 3; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) {
                break;
            }
            if (nums[first] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }

            for (int second = first + 1; second < n - 2; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) {
                    break;
                }
                if (nums[first] + nums[second] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }

                int fourth = n - 1;

                for (int third = second + 1; third < n - 1; third++) {
                    if (third > second + 1 && nums[third] == nums[third - 1]) {
                        continue;
                    }

                    while (third < fourth && nums[third] + nums[fourth] > target - (nums[first] + nums[second])) {
                        fourth--;
                    }
                    if (third == fourth) break;
                    if (nums[first] + nums[second] + nums[third] + nums[fourth] == target) {
                        ans.push_back({ nums[first], nums[second], nums[third], nums[fourth] });
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = solution.fourSum(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}