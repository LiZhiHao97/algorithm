#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        int fast = 2, slow = 2;

        while (fast < n) {
            if (nums[fast] != nums[slow - 2]) {
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
    vector<int> nums{1,1,1,2,2,3};
    int ans = solution.removeDuplicates(nums);

    cout << ans << endl;

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}