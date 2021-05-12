#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; i++) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--;
            }
             if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{2, 1, 2};
    solution.sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}