#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace  std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int ans = 0;

        while (low < high) {
            ans = max(ans, min(height[low], height[high]) * (high - low));

            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int a[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height(a, a + 9);
    int ans =  solution.maxArea(height);
    cout << ans << endl;
    return 0;
}
