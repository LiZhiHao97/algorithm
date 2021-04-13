#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool flag) {
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target || (flag && nums[mid] >= target)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false) - 1;

        if (leftIndex <= rightIndex && rightIndex < nums.size() && nums[leftIndex] == target && nums[rightIndex] == target) {
            return vector<int> {leftIndex, rightIndex};
        }

        return vector<int> {-1, -1};
    }
};

int main() {
    Solution solution;
    int a[6] = {5, 7, 7, 8, 8, 10};
    vector<int> nums(a, a + 6);
    int target = 8;

    vector<int> ans = solution.searchRange(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
