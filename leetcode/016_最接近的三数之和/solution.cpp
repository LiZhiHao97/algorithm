#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int first = 0; first < n; first++) {
            int second = first + 1, third = n - 1;
            while (second < third) {
                int cur = (nums[first] + nums[second] + nums[third]);
                if (cur - target > 0) {
                    third--;
                } else if (cur - target < 0) {
                    second++;
                } else {
                    return target;
                }
                if (abs(cur - target) < abs(ans -target)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int a[4] = { -1, 2, 1, -4 };
    int target = 1;
    vector<int> nums(a, a + 4);
    int ans =  solution.threeSumClosest(nums, target);
    cout << ans << endl;
    return 0;
}
