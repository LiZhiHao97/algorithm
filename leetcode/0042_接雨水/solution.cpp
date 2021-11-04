#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        if (n == 0) {
            return 0;
        }

        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height{4,2,0,3,2,5};

    int ans = solution.trap(height);

    cout << ans << endl;

    return 0;
}