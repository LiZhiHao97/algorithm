#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }

        for (int i = 0; i < n; i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};

    Solution solution;
    int ans = solution.findRepeatNumber(nums);

    cout << ans << endl;

}