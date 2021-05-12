#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int a[4] = {1, 3, 5, 6};
    vector<int> nums(a, a + 4);
    int target = 2;

    int ans = solution.searchInsert(nums, target);

    cout << ans << endl;

    return 0;
}
