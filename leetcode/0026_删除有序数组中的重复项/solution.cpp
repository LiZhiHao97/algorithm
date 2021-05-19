#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        int fast = 1, slow = 1;

        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 1};
    int ans = solution.removeDuplicates(nums);

    cout << ans << endl;

    return 0;
}