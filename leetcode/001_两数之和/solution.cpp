#include <iostream>
#include <vector>
#include <map>


using namespace  std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        vector<int> b(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i]) > 0) {
                b[0] = a[target - nums[i]];
                b[1] = i;
            }

            a[nums[i]] = i;
        }
        return b;
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
