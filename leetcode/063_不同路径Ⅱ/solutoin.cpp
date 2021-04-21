#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// dp + 滚动数组思想
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> f(n);

        f[0] = !obstacleGrid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};

int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid{{1, 0}};
    int ans = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << ans << endl;

    return 0;
}