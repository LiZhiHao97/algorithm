#include <iostream>
#include <vector>
#include <map>

using namespace  std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return vector<int>{i + 1, j + 1};
            }
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    Solution solution;
    int a[4] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums(a, a + 4);
    vector<int> result = solution.twoSum(nums, target);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
