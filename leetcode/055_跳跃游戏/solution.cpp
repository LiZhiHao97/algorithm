#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = nums.size();
        int maxPos = 0;

        for (int i = 0; i < end && i <= maxPos; i++) {
            maxPos = max(i + nums[i], maxPos);
            if (maxPos >= end - 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0};
    bool ans = solution.canJump(nums);
    cout << ans << endl;
    return 0;
}