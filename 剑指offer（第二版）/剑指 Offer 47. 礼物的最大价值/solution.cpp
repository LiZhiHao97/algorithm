class Solution {
private:
public:
    int maxValue(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) grid[i][j] = grid[i][j];
                else if (i == 0 && j != 0) grid[i][j] = grid[i][j] + grid[i][j - 1];
                else if (i != 0 && j == 0) grid[i][j] = grid[i][j] + grid[i - 1][j];
                else grid[i][j] = grid[i][j] + max(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};